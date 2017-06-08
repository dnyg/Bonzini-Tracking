#include "score.h"

void Score::write(Mat frame, string text) {
	drawBackground(frame, background_position);
	putText(frame, text, text_position, HersheyFonts::FONT_HERSHEY_PLAIN, text_width, text_color, thickness);
}

void Score::drawBackground(Mat frame, Rect position) {
	rectangle(frame, position, background_color, CV_FILLED);
}