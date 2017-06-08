#include "../include/goalkeeper.h"

GoalKeeper::GoalKeeper() {
	goalTime = time(0);
	left = vector<Point> { Point(0, 212), Point(0, 355), Point(84, 360), Point(100, 240) };
	right = vector<Point> { Point(935, 240), Point(955, 360), Point(1065, 355), Point(1045, 210) };
}

void GoalKeeper::checkForGoal(Point ball_position) {
	if (time(0) > goalTime + 3) {
		int result = checkIfBallIsInGoalArea(ball_position);

		if (result > 0) {
			goalTime = time(0);
			if (result == 1) {
				right_score++;
			}
			else {
				left_score++;
			}
		}
	}
}

int GoalKeeper::checkIfBallIsInGoalArea(Point ball_position) {

	//Check if ball is in left goal (1)
	if (findPointInArea(ball_position, left)) {
		return 1;
	}

	if (findPointInArea(ball_position, right)) {
		return 2;
	}

	return 0;
}

bool GoalKeeper::findPointInArea(Point ball, vector<Point> goal) {
	return cv::pointPolygonTest(goal, ball, false) == 1;
}

string GoalKeeper::getScoreText() {
	return to_string(left_score) + "-" + to_string(right_score);
}

void GoalKeeper::writeScore(Mat frame) {
	score.write(frame, getScoreText());
}

void GoalKeeper::drawGoals(Mat frame) {
	int thickness = 1;
	Scalar color = Scalar(0, 255, 255);

	polylines(frame, left, true, color, thickness);
	polylines(frame, right, true, color, thickness);
};