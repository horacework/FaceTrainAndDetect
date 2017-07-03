#include "stdafx.h"
#include "facialSampleCollect.h"

using namespace std;
using namespace cv;

bool isNum(string str)
{
	stringstream sin(str);
	double d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;
	return true;
}

void facialSampleCollect::Action() {
	
	int label;
	//char path[100];
	int size;
	while (1)
	{
		string tmp;
		cout <<endl<< "请输入该样本的标识（必须为int整数）："<<endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			label = stoi(tmp);
			break;
		}
		else
		{
			cout << "输入错误！" << endl;
		}
	}
	while (1)
	{
		string tmp;
		cout << endl << "请输入该样本的尺寸（正方形）（必须为int整数）：" << endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			size = stoi(tmp);
			break;
		}
		else
		{
			cout << "输入错误！" << endl;
		}
	}
	cout << label << "  " << size;
	
}


facialSampleCollect::facialSampleCollect()
{
}


facialSampleCollect::~facialSampleCollect()
{
}
