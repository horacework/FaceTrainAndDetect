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

	//从文件中读取图像  
	//IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);

	//创建窗口  
	//cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);

	//在指定窗口中显示图像  
	imshow(pstrWindowsTitle, img);

	//等待按键事件  
	waitKey(0);

	destroyWindow(pstrWindowsTitle);
}

openImage::~openImage()
{
}
