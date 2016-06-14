#include "turtle.h"
#include "draw.h"
#include <cmath>
#include <iostream>

using namespace std;

Turtle::Turtle(double x0, double y0, double dir0){
	xloc = x0;
	yloc = y0;
	direction = dir0;
	colr = draw::BLACK;
	drawOn = true;
}

void Turtle::turn(double deg){
	direction = direction + deg;
}

void Turtle::move(double dist){
	double x1 = xloc;
	double y1 = yloc;
	double radx = direction *(M_PI/180);
	double rady = direction * (M_PI/180);
	xloc = xloc + dist*cos(radx);
	yloc = yloc + dist*sin(rady);
	if(drawOn){
		draw::setcolor(colr);
		draw::line(x1, y1, xloc, yloc);
	}
}

void Turtle::setColor(Color c){
	colr = c;
}

void Turtle::off(){
	drawOn = false;
}

void Turtle::on(){
	drawOn = true;
}