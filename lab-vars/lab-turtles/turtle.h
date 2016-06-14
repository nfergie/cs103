#include "draw.h"

class Turtle{
public:
	Turtle(double x0, double y0, double dir0);
	void move(double dist);
	void turn(double deg);
	void setColor(Color c);
	void off();
	void on();

private:
	double xloc;
	double yloc;
	double direction;
	Color colr;
	bool drawOn;
};