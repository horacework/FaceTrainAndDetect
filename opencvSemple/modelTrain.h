#pragma once
class modelTrain
{
	public:
		modelTrain();
		~modelTrain();
		//void read_csv(const string& filename, vector<cv::Mat>& images, vector<int>& labels, char separator = ';');
		void Action();
		void Test();
};
