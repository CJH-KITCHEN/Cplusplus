#include <iostream>
#include"CJHTV.h"
#include"CJHClothing.h"
#include"CJHManager.h"
using namespace std;

bool checkdress(CJHProduct* &product) {

			if (product->getcode().find("A0002") != string::npos) {
				return true;
			}
			else {
				return false;
			}
			
}
bool checkg(CJHProduct*& product) {

	if (product->getptype().find("������ǰ") != string::npos) {
		return true;
	}
	else {
		return false;
	}

}

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

int main() {
	CJH::printName();

	cout << "2) CJHProduct �߻� Ŭ���� �����(�����ڴ� �����ϵ�, ��������� ��ü ���� �Ұ�)" << endl;
	//CJHProduct p("A0001", "������ǰ", 3, 1000);

	cout << "3) CJHTV ��ü ����" << endl;
	CJHProduct* tv = new CJHTV("A0001", "������ǰ", 3, 1000, "�Ǳ�����", "COM001", 62);

	cout << "4) CJHClothing ��ü ����" << endl;
	CJHProduct* pants = new CJHClothing("A0001", "�Ƿ�", 5, 120,"��������","�Ǳ�û����","XL");

	cout << "5) ���� �����ϱ�" << endl;
	tv->join("ȫ�浿");
	pants->join("��浿");
	pants->join("�̱浿");

	cout << "6) ��ü ���� ����ϱ�" << endl;
	cout << *tv << endl;
	cout << *pants << endl;

	cout << "7) CJHManager ��ü �����ϱ�" << endl;
	CJHManager manager("�Ǳ�����");

	cout << "8) CJHManager�� �Ǹ� ��ǰ �߰��ϱ�" << endl;
	manager.addItem(new CJHTV("E0001", "������ǰ", 3, 2000, "�Ǳ�����", "COM001", 62));
	manager.addItem(new CJHClothing("A0001", "�Ƿ�", 5, 120, "��������", "�Ǳ�û����", "XL"));
	manager.addItem(new CJHTV("E0002", "������ǰ", 2, 100, "��������", "SW001", 48));
	manager.addItem(new CJHClothing("A0002", "�Ƿ�", 2, 200, "������",  "���ǽ�", "XXL"));
	manager.addItem(new CJHClothing("A0003", "�Ƿ�", 3, 100, "������", "Ƽ����", "L"));

	cout << "9) �ǸŵǴ� ��ǰ ��ü ���� ���� ��������" << endl;
	auto items = manager.getItems();

	cout << "10) ���ǽ� ��ǰ ã��" << endl;
			
	vector<CJHProduct*>::iterator it = items.begin();
		it = find_if(it, items.end(), checkdress);
		if (it != items.end()) {
			(*it)->show();
		}
		else {
			cout << "�������� ����" << endl;
		}
	
		cout << "11)�Ǹ���ǰ �� ������ǰ�� ��� ����ϱ�" << endl;
		vector<CJHProduct*>::iterator it2 = items.begin();

		while (true) {
			it = find_if(it, items.end(), checkg);
			if (it != items.end()) {
				(*it)->show();
				it++;
			}
			else {
				cout << "�������� ����" << endl;
				break;
			}
		}
		
		cout << "12) ���� ���ݼ����� �����ؼ� ����ϱ�" << endl;
		sort(items.begin(), items.end(), [](CJHProduct* left, CJHProduct* right) {
			return left->getPrice() > right->getPrice();
			});
		for (auto i : items) {
			i->show();
			cout << endl;
		}
	

	



}