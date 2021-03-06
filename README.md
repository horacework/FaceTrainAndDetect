# FaceTrainAndDetect

Training and detecting facial models base on Opencv

## Requirements

* WebCamera
* Windows 7 or later
* OpenCV 3.0(with opencv_contrib) or later
* Microsoft Visual Studio 2015

In my test, folder [ORLface]() contains facial samples of 40 people (each person has 10 picture samples).

You can train your own samples by placing the samples in the specified folder.

You also can catch facial samples by your webcamera, the program will save the facial images in the specified folder automatically.

## Progress

* 2017-07-01 The code can train the model successfully. Through the test, the models is available.
* 2017-07-02 Improved the logic of loading facial samples. The directory structure such as -->SampleDIR-->label(int)-->xxx.bmp
* 2017-08-04 Added automatic catch facial sample program. Through the test, using the same webcamera for sample collection and facial  testing, the results are better.

## Usage

* Click the *.sln file

* Configure the OpenCV environment

* F5 Run!


## Install

Compiling Opencv_Contrib is more complex, see [opencv/opencv_contrib](https://github.com/opencv/opencv_contrib)

## Reference

[OpenCV实践之路——人脸识别之二模型训练](http://blog.csdn.net/xingchenbingbuyu/article/details/51407336)


## Licence

[MIT](https://github.com/horacework/FaceTrainAndDetect/blob/master/LICENSE)

