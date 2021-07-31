#include <iostream>
#include "gdgo.h"
#include "gdhong.h"
#include <string>
#include <sstream>
#include <ctime>
using namespace std;
using std::cin;

//int val = 100;


int main(void) {
	/*auto pnum1 = make_shared<int>();
	*pnum1 = 100;
	weak_ptr<int> pnum1_w(pnum1);

	auto pnum1_s = pnum1_w.lock();
	pnum1.reset();
	cout << pnum1_s.use_count() << endl;*/


	int a = 6;
	a++;
	cout << a << endl<< (a++) << endl;
	/*int** arr = new int* [5];
	for (int i = 0; i < 5; i++) {
		arr[i] = new int[3];
	}

	shared_ptr <shared_ptr<int[]>[]> parr(new shared_ptr<int[]>[5]);
	for (int i = 0; i < 5; i++) {
		parr[i] = shared_ptr<int[]>(new int[3]);
	}
	shared_ptr<shared_ptr<int[]>[]>parr1(new shared_ptr<int[]>[3]);
	for (int i = 0; i < 3; i++) {
		parr1[i] = shared_ptr<int[]>(new int[5]);
	}



	shared_ptr<shared_ptr<int[]>[]>parr4(new shared_ptr<int[]>[5]);
	for (int i = 0; i < 4; i++) {
		parr4[i] = shared_ptr<int[]>(new int[5]);
	}*/
	/*shared_ptr<int> pnum1 = make_shared<int>();
	*pnum1 = 100;
	cout << *pnum1 << endl;
	auto pnum1_copy = pnum1;
	*pnum1_copy = 200;
	cout << *pnum1 << endl;
	cout << *pnum1_copy << endl;
	cout << pnum1.use_count() << endl;
	cout << pnum1_copy.use_count() << endl;
	pnum1.reset();
	cout << *pnum1_copy << endl;
	cout << pnum1_copy.use_count() << endl;*/



	//int(*prr4)[3] = new int[3][3];
	//prr4[0][0] = 1;
	//prr4[1][0] = 2;

	//cout << *(prr4 + 1)[0] << endl;
	/*int* a = new int[4];
	a[0] = 50;
	a[1] = 51;
	a[2] = 52;
	a[3] = 53;
	for (int i = 0; i < 4; i++){
		cout << a[i] << endl;
	}
	delete[] a;
	a = nullptr;*/
	//srand((unsigned)time(NULL));
	//for (int i = 0; i < 5; i++) {
	//	cout << static_cast<char>('A' + rand()%4) << endl;

	///*}*/
	//string str("There are two needles in this haystack with needles.");
	//string str2("needle");
	//str.replace(str.find(str2), str2.length(), "preposition");
	//cout << str << '\n';
	//enum MyColor{red=10, green, blue=20};
	//MyColor bgColor = MyColor::green;
	//cout << bgColor << endl ;
	//string mystr1 = "ABC";
	//string mystr2 = "BBB";
	//cout << mystr2.compare(mystr1) << endl;
	/*string mystr;
	cout << "Enter your data(name kor eng math) : ";
	getline(cin, mystr);

	stringstream ss;
	ss.str(mystr);
	int mydata;
	while (ss >> mydata) {
		cout << mydata << endl;
	}*/
	/*tring str1;
	cout << "Enter price: " << endl;
	float price;
	cin >> str1;
	stringstream(str1) >> price;
	cout << "Enter quantity: " << endl;
	int quantity;
	cin >> str1;
	stringstream(str1) >> quantity;
	cout << "Total price : " << price * quantity << endl;*/
	//int val = 200;
	//::val += 1;
	//cout << ::val << endl;
	//gdhongNS::showName();
	//char s1[100];
	////string s1;

	//cin.getline(s1, 10, '\n');
	//cout << s1 << endl;
	//string mystr;
	//getline(cin, mystr);
	//cout << mystr << endl;
	//gdhongNS::showName();
	//gdgoNS::showName();
	//showName();
	/*function();
	B_COM::function();*/
	return 0;
}