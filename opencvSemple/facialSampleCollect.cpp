#include "stdafx.h"
#include "facialSampleCollect.h"
#include <io.h>  
#include <direct.h>  
#define PATH_DELIMITER '\\' 

using namespace std;
using namespace cv;


Mat faceROI;

//�ж������Ƿ�Ϊ����
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

//�����ļ���
bool createDirectory(const std::string folder) {
	std::string folder_builder;
	std::string sub;
	sub.reserve(folder.size());
	for (auto it = folder.begin(); it != folder.end(); ++it)
	{
		//cout << *(folder.end()-1) << endl;  
		const char c = *it;
		sub.push_back(c);
		if (c == PATH_DELIMITER || it == folder.end() - 1)
		{
			folder_builder.append(sub);
			if (0 != ::_access(folder_builder.c_str(), 0))
			{
				// this folder not exist  
				if (0 != ::_mkdir(folder_builder.c_str()))
				{
					// create failed  
					return false;
				}
			}
			sub.clear();
		}
	}
	return true;
}

void facialSampleCollect::Action() {

	VideoCapture capture;
	Mat frame;

	if (!face_cascade.load(face_cascade_name)) { 
		printf("--(!)Error loading face cascade\n"); 
		return; 
	};
	capture.open(0);
	if (!capture.isOpened()) {
		printf("--(!)Error opening video capture\n");
		return; 
	}

	while (1)
	{
		string tmp;
		cout <<endl<< "������������ı�ʶ������Ϊint��������"<<endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			label = stoi(tmp);
			if (label>0)
			{
				//������Ӧ�ļ���
				char t[3];
				_itoa(label, t, 10);
				createDirectory(path + t);
				break;
			}
			else
			{
				cout << "�������" << endl;
			}
			
		}
		else
		{
			cout << "�������" << endl;
		}
	}
	while (1)
	{
		string tmp;
		cout << endl << "�����������������������Ϊint��������" << endl;
		cin >> tmp;
		if (isNum(tmp))
		{
			num = stoi(tmp);
			if (num>0)
			{
				break;
			}
			else
			{
				cout << "�������" << endl;
			}
		}
		else
		{
			cout << "�������" << endl;
		}
	}

	while (capture.read(frame))
	{
		if (frame.empty())
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		detectAndDisplay(frame);

		int c = waitKey(20);
		if ((char)c == 13) {
			char t[3];
			_itoa(label, t, 10);
			char q[5];
			_itoa(count, q, 10);
			String savePath = path + t + "/" + q + ".jpg";
			cout << savePath<<" ---- ";
			resize(faceROI, faceROI, Size(100, 100), 0, 0, CV_INTER_LINEAR);
			imwrite(savePath, faceROI);
			cout << "������ɣ�" << endl;
			count++;
			if (count == num)
			{
				return;
			}
		}
		if ((char)c == 27)
		{
			return;
		}
	}
	
}

void facialSampleCollect::detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(100, 100), Size(1000, 1000));

	for (size_t i = 0; i < faces.size(); i++)
	{
		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);

		faceROI = frame_gray(faces[i]);
	}

	String windowName = "��ץ�������� - ��enter����������";
	imshow(windowName, frame);
}

facialSampleCollect::facialSampleCollect()
{
	face_cascade_name = "../model/haarcascade_frontalface_default.xml";
	path = "../train/";
	count = 0;
}


facialSampleCollect::~facialSampleCollect()
{
}
