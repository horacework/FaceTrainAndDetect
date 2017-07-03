// opencvSemple.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "openImage.h"
#include "faceDetectAndSave.h"
#include "modelTrain.h"
#include "facialSampleCollect.h"

using namespace std;
using namespace cv;

int main()
{
	int inputCmd;
	openImage *f = new openImage();
	faceDetectAndSave *f1 = new faceDetectAndSave();
	modelTrain *f2 = new modelTrain();
	facialSampleCollect *f3 = new facialSampleCollect();

	cout << "1 : 简单图片显示					-- openImage.cpp"			<<endl;
	cout << "2 : xml模型应用					-- faceDetectAndSave.cpp"	<<endl;
	cout << "3 : xml模型训练					-- modelTrain.cpp "			<<endl;
	cout << "4 : 人脸模型应用（读取摄像头帧）	-- faceDetectAndSave.cpp "	<<endl;
	cout << "5 : 人脸样本采集（读取摄像头帧）	-- facialSampleCollect.cpp "<<endl;
	cout << "请选择 : ";
	
	cin >> inputCmd;

	switch (inputCmd)
	{
	case 1 :
		f->Action();
		break;
	case 2 :
		f1->action();
		break;
	case 3:
		f2->Action();
		break;
	case 4:
		f2->Test();
		break;
	case 5:
		f3->Action();
		break;
	default:
		break;
	}

	waitKey(0);

	return 0;
}

