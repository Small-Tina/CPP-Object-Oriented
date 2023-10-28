#pragma once
#include <vector>
#include <string>
#include "CTriangle.h"
using namespace std;

class CquestionBanker
{
public:
	CquestionBanker();
	void InitQB(); //初始化题库
	void getQB();
	void getGrades();
	void getAvg();
	void addAnswer();
	void addQB();
	void deleteQB(int i); //删除题库
private:
	string QB_Name; //题库名称
	int QB_num; //题目数量
	CTriangle* triangle[10]; //三角形数组题库
	int grades;
	float avg;
};
