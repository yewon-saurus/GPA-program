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
	void Initialize(); // 멤버변수 초기화
	void Initialize(string name, int hakbun, int subnum, Subject* sub);
	void Remove(); // 동적메모리 해제(m_sub)
	void InputValue(int& i);
	void InputValue(string& str);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA();

	string GetName(); // m_name 리턴
	int GetHakbun(); // m_hakbun 리턴
	int GetSubNum(); // m_subnum 리턴
	float GetAveGPA(); // m_aveGPA 리턴

	friend void ShowData(const Student& s);
};
#endif