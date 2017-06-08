#pragma once
#include "opencv2/opencv.hpp"
#include "score.h";

using namespace cv;
using namespace std;

class GoalKeeper {

private:
	vector<Point> left;
	vector<Point> right;
	int left_score = 0;
	int right_score = 0;
	time_t goalTime;

	int checkIfBallIsInGoalArea(Point ball_position);
	bool findPointInArea(Point ball, vector<Point> goal);
	string getScoreText();

public:
	Score score;

	void checkForGoal(Point ball_position);
	void writeScore(Mat frame);
	void drawGoals(Mat frame);
	GoalKeeper();
};