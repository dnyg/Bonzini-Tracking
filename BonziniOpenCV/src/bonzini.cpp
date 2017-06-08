#include "../include/bonzini.h";

Bonzini::Bonzini(string filename)
{
	capture.open(filename);

	if (!capture.isOpened()) {
		throw exception("Could not open video stream");
	}

	dimensions = Size(1066, 600);
}

void Bonzini::start(int speed) {
	while (1) {

		//This should be fixed somehow..
		if (!getFrame()) {
			continue;
		}

		ball.find(frame);
		ball.drawCircle(frame);

		goalkeeper.drawGoals(frame); //Optional.. Goals don't really need to be drawn

		goalkeeper.checkForGoal(ball.getPosition());
		goalkeeper.writeScore(frame);

		imshow("Video", frame);
		waitKey(speed);
	}
}

bool Bonzini::getFrame() {
	capture >> frame;

	bool validFrame = !frame.empty();

	if (validFrame) {
		resize(frame, frame, dimensions);
	}

	return validFrame;
}

void Bonzini::skipFrames(int number) {
	for (size_t i = 0; i < number; i++)
	{
		capture >> frame;
	}
}