#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class Ball {

public:
	Ball();
	Point getPosition();
	void drawCircle(Mat frame);
	void find(Mat frame);
	Point position;
	Mat ball;
	
private:
	Point getCenter(vector<Point> position);
	Point findBiggestContour(vector<vector<Point>> contours);
	Scalar green_lower = Scalar(25, 90, 90);
	Scalar green_upper = Scalar(30, 255, 255);
};