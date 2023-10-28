#include "CquestionBanker.h"
#include <iostream>
using namespace std;

CquestionBanker::CquestionBanker() {
	this->QB_num = 0;
	this->QB_Name = "";
}

void CquestionBanker::InitQB()
{
	int QBNum;
	cout << "请输入题目总数(不超过10题)：";
	cin >> QBNum;
	float a, b, c;
	for (int index = 0; index < QBNum; index++) {
		cout << "请输入三边的长：";
		//验证三角形是否成立
		while (cin >> a >> b >> c)
		{
			if (a + b > c && a + c > b && b + c > a) {
				cout << "该三角形成立！" << endl;
				break;
			}
		}
		this->triangle[index] = new CTriangle();
		this->triangle[index]->setSide(a, b, c);
		this->QB_num++;
		this->triangle[index]->setID(this->QB_num);
	}
}
void CquestionBanker::getQB()
{
	int id;
	cout << "请输入您要查询的三角形题库编号:";
	cin >> id;
	id -= 1;
	float* side = this->triangle[id]->getSide();
	float periMeter = this->triangle[id]->getperiMeters();
	float area = this->triangle[id]->getarea();
	string type = this->triangle[id]->getType();
	if (id > this->QB_num) {
		cout << "对不起没有此题！" << endl;
		return;
	}
	cout << "该三角形的三边长为:";
	for (int index = 0; index < 3; index++) {
		cout << *(side + index) << " ";
	}
	cout << endl;
	cout << "该三角形的周长,面积,类型分别为" << endl;
	cout << periMeter << " " << area << " " << type << endl;
}
void CquestionBanker::getGrades()
{
	int score;
	for (int index = 0; index < this->QB_num; index++) {
		score = this->triangle[index]->correcting();
		this->grades += score;
	}
}
void CquestionBanker::getAvg()
{
	this->avg = (float)this->grades / (float)this->QB_num;
}
void CquestionBanker::addAnswer()
{
	for (int index = 0; index < this->QB_num; index++) {
		float Answer;
		cout << "请输入第" << index + 1 << "的答案" << endl;
		cin >> Answer;
		this->triangle[index]->setAnswer(Answer);
	}
}
void CquestionBanker::addQB()
{
	float a, b, c;
	cout << "请输入三边的长：";
	//验证三角形是否成立
	while (cin >> a >> b >> c)
	{
		if (a + b > c && a + c > b && b + c > a) {
			cout << "该三角形成立！" << endl;
			break;
		}
	}
	this->triangle[this->QB_num + 1] = new CTriangle();
	this->triangle[this->QB_num + 1]->setSide(a, b, c);
	this->QB_num++;
	this->triangle[this->QB_num + 1]->setID(this->QB_num);
}
void CquestionBanker::deleteQB(int index)
{
	if (index <= this->QB_num) {
		delete this->triangle[index - 1];
		for (int j = index; j < 10; j++) {
			this->triangle[j - 1] = this->triangle[j];
		}
		this->QB_num -= 1;
	}
}