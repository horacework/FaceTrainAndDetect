#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>  
#include <stdio.h>
class facialSampleCollect
{
public:
	facialSampleCollect();
	void Action();
	~facialSampleCollect();
	void detectAndDisplay(cv::Mat frame);
private:
	int label;

	cv::String path;

	int num;

	int count;

	cv::String face_cascade_name;
	cv::CascadeClassifier face_cascade;
};

