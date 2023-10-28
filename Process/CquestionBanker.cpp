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
	cout << "��������Ŀ����(������10��)��";
	cin >> QBNum;
	float a, b, c;
	for (int index = 0; index < QBNum; index++) {
		cout << "���������ߵĳ���";
		//��֤�������Ƿ����
		while (cin >> a >> b >> c)
		{
			if (a + b > c && a + c > b && b + c > a) {
				cout << "�������γ�����" << endl;
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
	cout << "��������Ҫ��ѯ�������������:";
	cin >> id;
	id -= 1;
	float* side = this->triangle[id]->getSide();
	float periMeter = this->triangle[id]->getperiMeters();
	float area = this->triangle[id]->getarea();
	string type = this->triangle[id]->getType();
	if (id > this->QB_num) {
		cout << "�Բ���û�д��⣡" << endl;
		return;
	}
	cout << "�������ε����߳�Ϊ:";
	for (int index = 0; index < 3; index++) {
		cout << *(side + index) << " ";
	}
	cout << endl;
	cout << "�������ε��ܳ�,���,���ͷֱ�Ϊ" << endl;
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
		cout << "�������" << index + 1 << "�Ĵ�" << endl;
		cin >> Answer;
		this->triangle[index]->setAnswer(Answer);
	}
}
void CquestionBanker::addQB()
{
	float a, b, c;
	cout << "���������ߵĳ���";
	//��֤�������Ƿ����
	while (cin >> a >> b >> c)
	{
		if (a + b > c && a + c > b && b + c > a) {
			cout << "�������γ�����" << endl;
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