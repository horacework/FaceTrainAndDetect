#include "stdafx.h"
#include "modelTrain.h"
#include <opencv2\opencv.hpp>
#include <opencv2\face.hpp>
#include <iostream>  
#include <stdio.h> 
#include <fstream>  
#include <sstream>  
#include <math.h> 

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

void modelTrain::Action()
{
	string fn_csv = "C:/Users/Administrator/Documents/visual studio 2015/Projects/opencvSemple/ORLface/at.txt";
	vector<Mat> images;
	vector<int> labels;
	//��clock()����ʱ  ����    
	clock_t  clockBegin, clockEnd;
	
	try
	{
		read_csv(fn_csv, images, labels);
	}
	catch (cv::Exception& e)
	{
		cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl; 
		exit(1);
	}
	

	cout << "==========��ʼѵ��==========" << endl;

	cout << "==========��ʼѵ��Eigenfaces����ģ��==========" << endl;
	clockBegin = clock();	
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();	// Eigenfaces
	model->train(images, labels);
	model->save("MyFacePCAModel.xml");
	clockEnd = clock();
	printf("Eigenfaces����ģ��ѵ������   ��ʱ %d ms \n", clockEnd - clockBegin);

	cout << "==========��ʼѵ��Fisherfaces����ģ��==========" << endl;
	clockBegin = clock();
	Ptr<FaceRecognizer> model1 = createFisherFaceRecognizer();	// Fisherfaces
	model1->train(images, labels);
	model1->save("MyFaceFisherModel.xml");
	clockEnd = clock();
	printf("Fisherfaces����ģ��ѵ������   ��ʱ %d ms \n", clockEnd - clockBegin);

	cout << "==========��ʼѵ��LBPH����ģ��==========" << endl;
	clockBegin = clock();
	Ptr<FaceRecognizer> model2 = createLBPHFaceRecognizer();	// �ֲ���ֵģʽֱ��ͼ (LBPH)
	model2->train(images, labels);
	model2->save("MyFaceLBPHModel.xml");
	clockEnd = clock();
	printf("Fisherfaces����ģ��ѵ������   ��ʱ %d ms \n", clockEnd - clockBegin);

	Mat testSample = images[images.size() - 1];
	int testLabel = labels[labels.size() - 1];

	// ����Բ���ͼ�����Ԥ�⣬predictedLabel��Ԥ���ǩ���(�������һ��ͼƬ������) 
	int predictedLabel = model->predict(testSample);
	int predictedLabel1 = model1->predict(testSample);
	int predictedLabel2 = model2->predict(testSample);

	// ����һ�ֵ��÷�ʽ�����Ի�ȡ���ͬʱ�õ���ֵ:  
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


