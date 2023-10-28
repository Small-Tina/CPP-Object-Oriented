#include <iostream>
#include "CquestionBanker.h"

int main() {
	CquestionBanker QBanker;
	QBanker.InitQB();
	int flag;
	cout << "请输入要进行的操作:" << endl << "1.输入你的周长答案" << endl << "2.向题库增加答案" << endl << "3.在题库删除题目" << endl << "4.查询题库题目" << endl << "0.退出系统" << endl;
	while (cin >> flag) {
		if (flag == 0) {
			break;
		}
		else if (flag == 1) {
			QBanker.addAnswer();
		}
		else if (flag == 2) {
			QBanker.addQB();
		}
		else if (flag == 3) {
			int index;
			cout << "请输入你要删除的题目ID号" << endl;
			cin >> index;
			QBanker.deleteQB(index);
		}
		else if (flag == 4) {
			QBanker.getQB();
		}
		else {
			cout << "输入有误,请重新输入";
		}
		cout << "请输入要进行的操作:" << endl << "1.输入你的周长答案" << endl << "2.向题库增加答案" << endl << "3.在题库删除题目" << endl << "4.查询题库题目" << endl << "0.退出系统" << endl;
	}
}