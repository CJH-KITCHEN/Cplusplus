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

	if (product->getptype().find("가전제품") != string::npos) {
		return true;
	}
	else {
		return false;
	}

}

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main() {
	CJH::printName();

	cout << "2) CJHProduct 추상 클래스 만들기(생성자는 존재하되, 명시적으로 객체 생성 불가)" << endl;
	//CJHProduct p("A0001", "가전제품", 3, 1000);

	cout << "3) CJHTV 객체 생성" << endl;
	CJHProduct* tv = new CJHTV("A0001", "가전제품", 3, 1000, "건국전자", "COM001", 62);

	cout << "4) CJHClothing 객체 생성" << endl;
	CJHProduct* pants = new CJHClothing("A0001", "의류", 5, 120,"남여공용","건국청바지","XL");

	cout << "5) 구매 참여하기" << endl;
	tv->join("홍길동");
	pants->join("김길동");
	pants->join("이길동");

	cout << "6) 객체 정보 출력하기" << endl;
	cout << *tv << endl;
	cout << *pants << endl;

	cout << "7) CJHManager 객체 생성하기" << endl;
	CJHManager manager("건국나라");

	cout << "8) CJHManager에 판매 물품 추가하기" << endl;
	manager.addItem(new CJHTV("E0001", "가전제품", 3, 2000, "건국전자", "COM001", 62));
	manager.addItem(new CJHClothing("A0001", "의류", 5, 120, "남여공용", "건국청바지", "XL"));
	manager.addItem(new CJHTV("E0002", "가전제품", 2, 100, "대학전자", "SW001", 48));
	manager.addItem(new CJHClothing("A0002", "의류", 2, 200, "여성용",  "원피스", "XXL"));
	manager.addItem(new CJHClothing("A0003", "의류", 3, 100, "남성용", "티셔츠", "L"));

	cout << "9) 판매되는 제품 전체 저장 정보 가져오기" << endl;
	auto items = manager.getItems();

	cout << "10) 원피스 제품 찾기" << endl;
			
	vector<CJHProduct*>::iterator it = items.begin();
		it = find_if(it, items.end(), checkdress);
		if (it != items.end()) {
			(*it)->show();
		}
		else {
			cout << "존재하지 않음" << endl;
		}
	
		cout << "11)판매제품 중 가전제품만 모두 출력하기" << endl;
		vector<CJHProduct*>::iterator it2 = items.begin();

		while (true) {
			it = find_if(it, items.end(), checkg);
			if (it != items.end()) {
				(*it)->show();
				it++;
			}
			else {
				cout << "존재하지 않음" << endl;
				break;
			}
		}
		
		cout << "12) 높은 가격순으로 정렬해서 출력하기" << endl;
		sort(items.begin(), items.end(), [](CJHProduct* left, CJHProduct* right) {
			return left->getPrice() > right->getPrice();
			});
		for (auto i : items) {
			i->show();
			cout << endl;
		}
	

	



}