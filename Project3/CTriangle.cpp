#include "CTriangle.h"

CTriangle::CTriangle()
{
	this->side_a = 0;
	this->side_b = 0;
	this->side_c = 0;
	this->periMeter = 0;
	this->area = 0;
	this->type = "";
}

void CTriangle::setID(int ids)
{
	this->id = ids;
}

void CTriangle::setSide(float a, float b, float c)
{
	this->side_a = a;
	this->side_b = b;
	this->side_c = c;
	this->periMeter = a + b + c;
	float q = this->periMeter / 2;
	this->area = sqrt(q * (q - this->side_a) * (q - this->side_b) * (q - this->side_c));
	if (a == b && b == c) {
		this->type = "等边三角形";
	}
	else if (a == b || a == c || b == c) {
		this->type = "等腰三角形";
	}
	else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
		this->type = "直角三角形";
	}
	else {
		this->type = "普通三角形";
	}
	return;
}

float* CTriangle::getSide()
{
	static float side[3] = { this->side_a, this->side_b, this->side_c };
	return side;
}
float CTriangle::getperiMeters()
{

	return this->periMeter;
}

float CTriangle::getarea()
{
	return this->area;
}
string CTriangle::getType()
{
	return this->type;
}

void CTriangle::setAnswer(float Answer)
{
	this->userAnswer = Answer;
}

int CTriangle::correcting()
{
	if (this->userAnswer == this->periMeter) {
		return 1;
	}
	return 0;
}
