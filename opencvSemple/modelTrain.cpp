#include "stdafx.h"
#include "modelTrain.h"
#include <opencv2\opencv.hpp>
#include <opencv2\face.hpp>
#include <iostream>  
#include <stdio.h> 
#include <fstream>  
#include <sstream>  
#include <math.h> 
#include <direct.h>
#include <io.h>

using namespace std;
using namespace cv;
using namespace face;

modelTrain::modelTrain()
{
}


modelTrain::~modelTrain()
{
}

void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);
	if (!file) {
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	string line, path, classlabel;
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		if (!path.empty() && !classlabel.empty()) {
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}

void readDirImageAndLabel (const string& path, string label, vector<Mat>& images, vector<int>& labels) {
	_finddata_t file;
	long lf;
	string p,tempPath;
	if ((lf = _findfirst(p.assign(path).append("\\").append(label).append("\\*").c_str(), &file)) == -1) {
		cout << path << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//输出文件名
			if (strcmp(file.name, ".") != 0 && strcmp(file.name, "..") != 0 && strchr(file.name,'.bmp') != NULL){
				cout <<"已载入文件： "<< file.name << endl;
				images.push_back(imread(tempPath.assign(path).append("\\").append(label).append("\\").append(file.name), 0));
				labels.push_back(atoi(label.c_str()));
			}
		}
	}
	_findclose(lf);
}

void loadImageAndLabel(const string& path, vector<Mat>& images, vector<int>& labels) {

	_finddata_t file;
	long lf;
	string p;
	//输入文件夹路径  
	if ((lf = _findfirst(p.assign(path).append("\\*").c_str(), &file)) == -1) {
		cout << path << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//输出文件名
			//获取所有样本文件夹(文件夹名字必须为整形数字)
			if (strcmp(file.name, ".")==0 | strcmp(file.name, "..") == 0) {
				continue;
				//cout<<file.name<<endl;
			}
			cout <<"文件夹  =======  "<< file.name << endl;
			readDirImageAndLabel(path, file.name, images, labels);
			//files.push_back(file.name);
		}
	}
	_findclose(lf);
	
}

void modelTrain::Action()
{
	//string fn_csv = "C:/Users/Administrator/Documents/visual studio 2015/Projects/opencvSemple/ORLface/at.txt";
	string str = "C:\\Users\\Administrator\\Documents\\visual studio 2015\\Projects\\opencvSemple\\train";
	vector<Mat> images;
	vector<int> labels;
	//用clock()来计时  毫秒    
	clock_t  clockBegin, clockEnd;
	
	try
	{
		//read_csv(fn_csv, images, labels);
		loadImageAndLabel(str, images, labels);
	}
	catch (cv::Exception& e)
	{
		cerr << "Error opening file \""  << "\". Reason: " << e.msg << endl; 
		exit(1);
	}
	

	cout << "==========开始训练==========" << endl;

	cout << "==========开始训练Eigenfaces人脸模型==========" << endl;
	clockBegin = clock();	
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();	// Eigenfaces
	model->train(images, labels);
	model->save("MyFacePCAModel1.xml");
	clockEnd = clock();
	printf("Eigenfaces人脸模型训练结束   用时 %d ms \n", clockEnd - clockBegin);

	cout << "==========开始训练Fisherfaces人脸模型==========" << endl;
	clockBegin = clock();
	Ptr<FaceRecognizer> model1 = createFisherFaceRecognizer();	// Fisherfaces
	model1->train(images, labels);
	model1->save("MyFaceFisherModel1.xml");
	clockEnd = clock();
	printf("Fisherfaces人脸模型训练结束   用时 %d ms \n", clockEnd - clockBegin);

	cout << "==========开始训练LBPH人脸模型==========" << endl;
	clockBegin = clock();
	Ptr<FaceRecognizer> model2 = createLBPHFaceRecognizer();	// 局部二值模式直方图 (LBPH)
	model2->train(images, labels);
	model2->save("MyFaceLBPHModel1.xml");
	clockEnd = clock();
	printf("Fisherfaces人脸模型训练结束   用时 %d ms \n", clockEnd - clockBegin);

	Mat testSample = images[images.size() - 1];
	int testLabel = labels[labels.size() - 1];

	// 下面对测试图像进行预测，predictedLabel是预测标签结果(利用最后一张图片做测试) 
	int predictedLabel = model->predict(testSample);
	int predictedLabel1 = model1->predict(testSample);
	int predictedLabel2 = model2->predict(testSample);

	// 还有一种调用方式，可以获取结果同时得到阈值:  
	//      int predictedLabel = -1;  
	//      double confidence = 0.0;  
	//      model->predict(testSample, predictedLabel, confidence);  

	string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
	string result_message1 = format("Predicted class = %d / Actual class = %d.", predictedLabel1, testLabel);
	string result_message2 = format("Predicted class = %d / Actual class = %d.", predictedLabel2, testLabel);

	cout << result_message << endl;
	cout << result_message1 << endl;
	cout << result_message2 << endl;

	system("pause");
	//waitKey(0);
}

void readDirImageToPredict(const string& path, Ptr<FaceRecognizer> model) {
	_finddata_t file;
	long lf;
	string p, tempPath;
	if ((lf = _findfirst(p.assign(path).append("\\*").c_str(), &file)) == -1) {
		cout << path << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//输出文件名
			if (strcmp(file.name, ".") != 0 && strcmp(file.name, "..") != 0 && strchr(file.name, '.bmp') != NULL) {
				cout << "已载入文件： " << file.name << "=======";
				cout << "预测结果：" <<model->predict(imread(tempPath.assign(path).append("\\").append(file.name), 0))<<endl;
				
				//labels.push_back(atoi(label.c_str()));
			}
		}
	}
	_findclose(lf);
}

void modelTrain::Test() {

	string FaceTestPath = "C:\\Users\\Administrator\\Documents\\visual studio 2015\\Projects\\opencvSemple\\ORLfaceTest";
	String MyFaceFisherModel = "MyFaceFisherModel.xml";
	String MyFacePCAModel = "MyFacePCAModel.xml";
	String MyFaceLBPHModel = "MyFaceLBPHModel.xml";

	Ptr<FaceRecognizer> FisherModel;
	Ptr<FaceRecognizer> PCAModel;
	Ptr<FaceRecognizer> LBPHModel;

	FisherModel = createFisherFaceRecognizer();
	FisherModel->load(MyFaceFisherModel);
	PCAModel = createEigenFaceRecognizer();
	PCAModel->load(MyFacePCAModel);
	LBPHModel = createLBPHFaceRecognizer();
	LBPHModel->load(MyFaceLBPHModel);

	cout << "==========开始测试人脸Fisher模型==========" << endl;
	readDirImageToPredict(FaceTestPath, FisherModel);

	cout << "==========开始测试人脸PCA模型==========" << endl;
	readDirImageToPredict(FaceTestPath, PCAModel);

	cout << "==========开始测试人脸LBPH模型==========" << endl;
	readDirImageToPredict(FaceTestPath, LBPHModel);

}

