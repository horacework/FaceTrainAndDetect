// opencvSemple.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "openImage.h"
#include "faceDetectAndSave.h"
#include "modelTrain.h"

using namespace std;
using namespace cv;

int main()
{
	int inputCmd;
	openImage *f = new openImage();
	faceDetectAndSave *f1 = new faceDetectAndSave();
	modelTrain *f2 = new modelTrain();

	cout << "1 : ��ͼƬ��ʾ -- openImage.cpp"			<<endl;
	cout << "2 : xmlģ��Ӧ��  -- faceDetectAndSave.cpp"	<<endl;
	cout << "3 : xmlģ��ѵ��  -- modelTrain.cpp "		<<endl;
	cout << "��ѡ�� : ";
	
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
	default:
		break;
	}

	waitKey(0);

	return 0;
}

