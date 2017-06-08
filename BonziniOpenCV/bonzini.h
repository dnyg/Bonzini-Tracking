#pragma once
#include "opencv2/opencv.hpp"
#include "goalkeeper.h";
#include "ball.h";

using namespace cv;
using namespace std;

class Bonzini {

private:
	Mat frame;
	GoalKeeper goalkeeper;
	VideoCapture capture;
	Ball ball;
	Size dimensions;

	bool getFrame();
	void skipFrames(int number);

public:
	Bonzini(string filename);
	void start(int speed);
};