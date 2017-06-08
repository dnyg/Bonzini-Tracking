#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class Score {
public:
	void write(Mat frame, string text);

private:
	void drawBackground(Mat frame, Rect position);

	const Scalar text_color = Scalar(0, 0, 255, 255);
	const Scalar background_color = Scalar(0, 0, 0, 0);
	const Rect background_position = Rect(Point(0, 0), Point(90, 40));
	const Point text_position = Point(10, 30);
	const int text_width = 2;
	const int thickness = 3;
};