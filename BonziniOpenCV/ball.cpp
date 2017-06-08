#include "ball.h";

Ball::Ball() {
	position = Point(-100, -100);
	green_lower = Scalar(25, 90, 90);
	green_upper = Scalar(30, 255, 255);
}

void Ball::find(Mat frame) {
	cvtColor(frame, ball, COLOR_BGR2HSV);
	inRange(ball, green_lower, green_upper, ball);
	erode(ball, ball, getStructuringElement(MorphShapes::MORPH_ELLIPSE, Size(3, 3), Point(-1, -1)), Point(-1, -1));
	dilate(ball, ball, getStructuringElement(MorphShapes::MORPH_ELLIPSE, Size(3, 3), Point(-1, -1)));

	vector<vector<Point>> contours;
	findContours(ball.clone(), contours, RetrievalModes::RETR_EXTERNAL, ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	float radius;
	Point2f center;

	vector<vector<Point>> filtered_contours;

	for (size_t i = 0; i < contours.size(); i++)
	{
		minEnclosingCircle(contours[i], center, radius);

		if (radius > 5) {
			filtered_contours.push_back(contours[i]);
		}
	}

	if (filtered_contours.size() > 0) {
		position = findBiggestContour(filtered_contours);
	}
	else {
		position = Point(-100, -100);
	}
}

Point Ball::findBiggestContour(vector<vector<Point>> contours) {
	size_t size = contours.size();
	double largest_area = 0;
	size_t index = 0;

	for (size_t i = 0; i < size; i++)
	{
		double contour = contourArea(contours[i], false);

		if (contour > largest_area) {
			largest_area = contour;
			index = i;
		}
	}

	return getCenter(contours[index]);
}

Point Ball::getPosition() {
	return position;
}

Point Ball::getCenter(vector<Point> position) {
	Moments M = moments(position);
	Point center = Point((int)M.m10 / M.m00, (int)M.m01 / M.m00);
	return center;
}

void Ball::drawCircle(Mat frame) {
	circle(frame, position, 15, Scalar(0, 255, 255), 2);
}