// opencvSemple.cpp : �������̨Ӧ�ó������ڵ㡣
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

	cout << "1 : ��ͼƬ��ʾ					-- openImage.cpp"			<<endl;
	cout << "2 : xmlģ��Ӧ��					-- faceDetectAndSave.cpp"	<<endl;
	cout << "3 : xmlģ��ѵ��					-- modelTrain.cpp "			<<endl;
	cout << "4 : ����ģ��Ӧ�ã���ȡ����ͷ֡��	-- faceDetectAndSave.cpp "	<<endl;
	cout << "5 : ���������ɼ�����ȡ����ͷ֡��	-- facialSampleCollect.cpp "<<endl;
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

