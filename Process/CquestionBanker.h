#pragma once
#include <vector>
#include <string>
#include "CTriangle.h"
using namespace std;

class CquestionBanker
{
public:
	CquestionBanker();
	void InitQB(); //��ʼ�����
	void getQB();
	void getGrades();
	void getAvg();
	void addAnswer();
	void addQB();
	void deleteQB(int i); //ɾ�����
private:
	string QB_Name; //�������
	int QB_num; //��Ŀ����
	CTriangle* triangle[10]; //�������������
	int grades;
	float avg;
};
