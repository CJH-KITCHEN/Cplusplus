#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int random() {
	return rand() % 100;
}

bool checkKim(const Student& std) {
	if (std.getName().find("김") != string::npos) {
		//여기서는 성이 김이 아니라 중간에 김이 들어가도 다 찾아냄 ㅋ
		return true;
	}
	else {
		return false;
	}
}

int main() {
	//수업 실습 2
	vector<Student> std;
	std.push_back(Student("2001", "홍길동", 80));
	std.push_back(Student("2004", "김길동", 70));
	std.push_back(Student("2003", "최길동", 90));
	std.push_back(Student("2002", "이길동", 100));
	//std.push_back(Student("2005", "김길자", 60));
	std.push_back(Student("2005", "김길동", 60));
	std.push_back(Student("2007", "최길자", 95));
	//std.push_back(Student("2006", "김철수", 75));
	std.push_back(Student("2006", "김길동", 75));



	//vector<Student>::iterator it = find(std.begin(), std.end(), Student("2003", "최길동", 90));
	//vector<Student>::iterator it = find(std.begin(), std.end(), "최길동");
	
	//vector<Student>::iterator it = remove(std.begin(), std.end(), "김길동"); //뒤에 벡터 정리가 안됨, erase같이써야됨
	vector<Student>::iterator it = remove_if(std.begin(), std.end(), [](const Student& s) {return s.getScore() >= 90; });
	std.erase(it, std.end()); //it부터 std.end()까지 다 지움  
	for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; });
	
	/*vector<Student>::iterator it = std.begin();
	while (true) {
		//it = find_if(it, std.end(), checkKim);
		//it = find_if(it, std.end(), Student("2003", "최길동", 90)); //이렇게 함수 대신에 객체 넣을려면 객체 클래스에 함수 operator()를 오버로딩해줘야함
		it = find_if(it, std.end(), [](const Student& s) {return s.getScore() >= 90; }); //요고는 익명함수 사용한 경우 
		if (it != std.end()) {
			cout << distance(std.begin(), it) << "번째 존재함 : " << *it << endl;
			it++;
		}
		else {
			cout << "없음" << endl;
			break;
		}
	}*/


	//sort(std.begin(), std.end(),greater<Student>());//여기서 타입 넣어주면 student객체 연산자에 const붙여줘야함
	/*sort(std.begin(), std.end(), [](const Student& left, const Student& right) {
		return left.getId() < right.getId();
		});

	for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; }); */


	//수업 실습 1
	/*vector<int> vec(10);
	//generate(vec.begin(), vec.end(), random);
	generate(vec.begin(), vec.end(), [] {return rand() % 100; });
	//sort(vec.begin(), vec.end(), greater<int>());
	
	vector<int> vec2(5);
	generate(vec2.begin(), vec2.end(), [] {return rand() % 50; });

	cout << vec.size() << " ," << vec2.size() << endl;
	cout << vec.data() << " ," << vec2.data() << endl; // 스왑하기전 주소 값
	vec.swap(vec2);
	cout << vec.size() << " ," << vec2.size() << endl;
	cout << vec.data() << " ," << vec2.data() << endl; // 스왑 후 주소 값(주소 값들이 서로 바뀜 새로 생기는게 ㄴㄴ)

	//사이즈가 달라도 swap이 되노

	for_each(vec.begin(), vec.end(), [](const int i) {cout << i << endl; });*/
}