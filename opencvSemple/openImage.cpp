#include "stdafx.h"
#include "openImage.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

openImage::openImage()
{
}

void openImage::Action() {
	const char *pstrImageName = "C:/Users/Administrator/Desktop/1.jpg";
	const char *pstrWindowsTitle = "OpenCV Sample Open Image";

	Mat img = imread(pstrImageName);

	//���ļ��ж�ȡͼ��  
	//IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);

	//��������  
	//cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);

	//��ָ����������ʾͼ��  
	imshow(pstrWindowsTitle, img);

	//�ȴ������¼�  
	waitKey(0);

	destroyWindow(pstrWindowsTitle);
}

openImage::~openImage()
{
}
