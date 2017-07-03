#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\face.hpp>
#include <iostream>  
#include <stdio.h>

class faceDetectAndSave
{
public:
	faceDetectAndSave();
	int action();
	void detectAndDisplay(cv::Mat frame);
	void detectAndVerifyModel(cv::Mat frame);
	~faceDetectAndSave();

};
