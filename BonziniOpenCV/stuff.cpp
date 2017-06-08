#include "opencv2/opencv.hpp";

using namespace cv;

class Stuff {

	//Attempt to find blue goal
	void findPathway(Mat frame) {
		Mat ball;
		
		Scalar dark_low = Scalar(40, 35, 63);
		Scalar dark_up = Scalar(92, 255, 255);
		cvtColor(frame, ball, cv::COLOR_BGR2HSV);
		inRange(ball, dark_low, dark_up, ball);
		frame = ball;
	}
};