//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Developer: Ava Teegarden
// date: 10/17/2022
// name: lines.cpp
// ~this file was brought to you through the power of  gummybears~
// function: class functions for the class lineType
//           all the lines are in format:   ax + by = c
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "lines.h"

lineType::lineType()//sets to 1.0 default
{
	a = 1.0;
	b = 1.0;
	c = 1.0;

}


void lineType::setCoefficient(double a_in, double b_in, double c_in)//sets line coefficients
{
	a = a_in;
	b = b_in;
	c = c_in;

}

void lineType::displayLine()//displays line equation
{
	cout << setprecision(2) << a << "x  +  " << b << "y  =  " << c << endl;

}


void lineType::lineSlope()//calcs displays lines slope
{
	double slope;//wee output

	if (a == 0) {
		cout << "slope: horizontal" << endl;
	}
	else if (b == 0) {
		cout << "slope: vertical" << endl;
	}
	else{
		slope = -(a / b);
		cout << setprecision(2) << "slope: " << slope << endl;
	}

}

void lineType::lineIntersection(lineType line)//displays point of intersection between 2 lines
{
	double x;
	double y;//intersection values

	x = ((line.b * c) - (b * line.c)) / ((a * line.b) - (line.a * b));//knarly equation to determine x point

	y = ((line.c * a) - (c * line.a)) / ((a * line.b) - (line.a * b));//knarly equation to determine y point

	//output the point pair
	cout << setprecision(2) << fixed;
	cout << "Intersects at: (" << x << "," << y << ")" << endl;


}

//operators---------------------------------------------------------------------------------
bool lineType::operator==(lineType line)//returns bool true if 2  lines are equal, including multiples
{
	bool isEqual;
	if ((a == line.a) && (b == line.b) && (c == line.c)) {//if lines are exactly equal, true
		isEqual = true;
	}
	//some quick k declarations
	double ka = a / line.a;
	double kb = b / line.b;
	double kc = c / line.c;

	if ((ka == kb) && (kb == kc)) {//if all the ks are the same, its equal through ratio
		isEqual = true;
	}
	else isEqual = false;

	return isEqual;
}

bool lineType::operator||(lineType line)//returns true if 2 lines are parallel
{

	//check for horizontal/vertical sneaky lines
	if ((a == 0) && (line.a == 0)) {
		return true; //horizontal parallel
	}
	if ((b == 0) && (line.b == 0)) {
		return true; //vertical parallel 
	}
	else {
		double slope1 = -(a / b);
		double slope2 = -(line.a /line.b);//slope info holders

		if (slope1 == slope2) {

			return true;//normal slope parallel
		}
		else { return false; }

	}


}
bool lineType::operator&&(lineType line)//returns tue if 2 lines are perpendicular
{
	if ((a == 0) && (line.b == 0)) {
		return true; //horizontal & vertical
	}
	if ((b == 0) && (line.a == 0)) {
		return true; //vertical & horizontal 
	}
	else {
		double slope1 = -(a / b);
		double slope2 = -(line.a / line.b);//slope info holders

		if ((slope1*slope2) == -1) { //if the product of lines' slopes are =-1 then perpendicular

			return true;
		}
		else { return false; }

	}


}

