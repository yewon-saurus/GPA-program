#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;
class Student {
protected:
	string m_name;
	int m_hakbun;
	int m_subnum;
	Subject* m_sub;
	float m_avgGPA;

public:
	void InputData(); // 멤버변수 값 입력
	void PrintData() const; // 멤버변수 값 출력
	void CalcAveGPA();
	void Modify();

	string GetName() const; // m_name 리턴
	int GetHakbun() const; // m_hakbun 리턴
	int GetSubNum() const; // m_subnum 리턴
	float GetAveGPA() const; // m_aveGPA 리턴
	Subject* SubSearch(string subname) const; // 과목 탐색

	friend void ShowData(const Student& s);

	Student(); // NULL 또는 0으로 초기화
	Student(string name, int hakjum, int subnum, Subject* sub);
	// 멤버변수의 값을 입력된 인자로 초기화, 이때 깊은 복사를 할 수 있도록 구현
	// 또한 평균평점은 입력되지 않으므로 평균 평점 계산 함수 호출하여 입력
	Student(const Student& std); // 다른 Student 클래스의 멤버변수의 값으로 초기화
	~Student(); // 동적 할당 받은 메모리 정리
};
#endif