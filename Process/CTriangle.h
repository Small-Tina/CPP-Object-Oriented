#pragma once
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class CTriangle
{
public:
	CTriangle();
	void setID(int ids);
	void setSide(float a, float b, float c);
	float* getSide();
	float getperiMeters();
	float getarea();
	string getType();
	void setAnswer(float Answer);
	int correcting();
private:
	int id;
	float side_a;
	float side_b;
	float side_c;
	float periMeter;
	float area;
	string type;
	float userAnswer;
};
