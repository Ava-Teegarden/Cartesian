#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;


//line class declaration
class lineType {

public:

	//constructor
	lineType();//sets to 1.0 default

	void setCoefficient(double a_in, double b_in, double c_in);//sets line coefficients ax + by = c
	void displayLine();//displays line equation
	void lineSlope();//calcs displays lines slope

	//operators
	bool operator==(lineType line);//returns bool true if 2  lines are equal, including multiples
	bool operator||(lineType line);//returns true if 2 lines are parallel
	bool operator&&(lineType line);//returns tue if 2 lines are perpendicular

	void lineIntersection(lineType line);//displays point of intersection between 2 lines

private:

	double a, b, c;//coefficient line vals

};