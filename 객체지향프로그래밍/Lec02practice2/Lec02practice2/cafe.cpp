#include <iostream>
using namespace std;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

int main() {

	CJH::printName();

	int select;
	int ame = 0, latte = 0;
	do {
		cout << "1) �Ƹ޸�ī��(100��) 2)ī���(200��) 3)���� 4)����\n";
		cout << "�����ϼ��� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "�Ƹ޸�ī�븦 �ֹ��ϼ̽��ϴ�.\n\n";
			ame++;
			break;
		case 2:
			cout << "ī��󶼸� �ֹ��ϼ̽��ϴ�.\n\n";
			latte++;
			break;
		case 3:
			cout << "==================\n�����ݾ�\n==================\n";
			cout << "�Ƹ޸�ī�� " << ame << "�� " << ame * 100 << "��" << endl;
			cout << "ī��� " << latte << "�� " << latte * 200 << "��" << endl;
			cout << "==================\n�� " << (ame * 100) + (latte * 200) << "��\n==================\n\n";
			cout << "������ �Ϸ�Ǿ����ϴ�.\n\n";
			ame = 0, latte = 0;
			break;
		}
	} while (select != 4);

	return 0;
}