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
		cout <<endl<< "������������ı�ʶ������Ϊint��������"<<endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			label = stoi(tmp);
			break;
		}
		else
		{
			cout << "�������" << endl;
		}
	}
	while (1)
	{
		string tmp;
		cout << endl << "������������ĳߴ磨�����Σ�������Ϊint��������" << endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			size = stoi(tmp);
			break;
		}
		else
		{
			cout << "�������" << endl;
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
