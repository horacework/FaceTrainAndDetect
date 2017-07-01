#pragma once
#include "faceDetectAndSave.h"
#include <opencv2\opencv.hpp>  
#include <iostream>  
#include <stdio.h>

class faceDetectAndSave
{
public:
	faceDetectAndSave();
	int action();
	void detectAndDisplay(cv::Mat frame);
	~faceDetectAndSave();

};
