#include "stdafx.h"
#include "faceDetectAndSave.h"

using namespace std;
using namespace cv;

/** Function Headers */
//void detectAndDisplay(Mat frame);

/** Global variables */
String face_cascade_name = "../model/haarcascade_frontalface_default.xml";
String eyes_cascade_name = "../model/haarcascade_eye_tree_eyeglasses.xml";
String plate_cascade_name = "../model/haarcascade_russian_plate_number.xml";

CascadeClassifier face_cascade;   //定义人脸分类器  
CascadeClassifier eyes_cascade;   //定义人眼分类器  
CascadeClassifier plate_cascade;   //定义人眼分类器  

String window_name = "Capture - Face detection";

/** @function main */
int faceDetectAndSave::action()
{
	Mat frame = imread("C:/Users/Administrator/Desktop/006.jpg");

	//VideoCapture capture;  
	//Mat frame;  

	//-- 1. Load the cascades  
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };
	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };

	if (!plate_cascade.load(plate_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };

	//-- 2. Read the video stream  
	//capture.open(0);  
	//if (!capture.isOpened()) { printf("--(!)Error opening video capture\n"); return -1; }  

	//while (capture.read(frame))  
	//{  
	//  if (frame.empty())  
	//  {  
	//      printf(" --(!) No captured frame -- Break!");  
	//      break;  
	//  }  

	//-- 3. Apply the classifier to the frame  
	detectAndDisplay(frame);

	int c = waitKey(0);
	if ((char)c == 27) { return 0; } // escape  
									 //}  

	return 0;
}

/** @function detectAndDisplay */
void faceDetectAndSave::detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	//equalizeHist(frame_gray, frame_gray);

	//-- Detect faces  
	//face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));
	plate_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(10, 10), Size(1000, 1000));

	for (size_t i = 0; i < faces.size(); i++)
	{
		//Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);  
		//ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);  
		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//-- In each face, detect eyes  
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 1, CV_HAAR_DO_ROUGH_SEARCH, Size(50, 50));

		for (size_t j = 0; j < eyes.size(); j++)
		{
			Rect rect(faces[i].x + eyes[j].x, faces[i].y + eyes[j].y, eyes[j].width, eyes[j].height);

			//Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);  
			//int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);  
			//circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);  
			rectangle(frame, rect, Scalar(0, 255, 0), 2, 8, 0);
		}
	}
	//-- Show what you got  
	namedWindow(window_name);
	imshow(window_name, frame);
}

faceDetectAndSave::faceDetectAndSave()
{

}


faceDetectAndSave::~faceDetectAndSave()
{
}
