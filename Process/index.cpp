#include <iostream>
#include "CquestionBanker.h"

int main() {
	CquestionBanker QBanker;
	QBanker.InitQB();
	int flag;
	cout << "������Ҫ���еĲ���:" << endl << "1.��������ܳ���" << endl << "2.��������Ӵ�" << endl << "3.�����ɾ����Ŀ" << endl << "4.��ѯ�����Ŀ" << endl << "0.�˳�ϵͳ" << endl;
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
			cout << "��������Ҫɾ������ĿID��" << endl;
			cin >> index;
			QBanker.deleteQB(index);
		}
		else if (flag == 4) {
			QBanker.getQB();
		}
		else {
			cout << "��������,����������";
		}
		cout << "������Ҫ���еĲ���:" << endl << "1.��������ܳ���" << endl << "2.��������Ӵ�" << endl << "3.�����ɾ����Ŀ" << endl << "4.��ѯ�����Ŀ" << endl << "0.�˳�ϵͳ" << endl;
	}
}