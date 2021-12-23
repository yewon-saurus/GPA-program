#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>

using namespace std;
class Subject {
protected:
	string m_name;
	int m_hakjum;
	string m_grade;
	float m_GPA;

public:
	void InputValue(int& i);
	void InputValue(string& str);
	void InputData();	// 멤버변수 값 입력(with InputValue)
	void PrintTitle();
	void PrintData();
	void CalcGPA();
	void Modify();

	string GetName(); // m_name 리턴
	int GetHakjum(); // m_hakjum 리턴
	string GetGrade(); // m_grade 리턴
	float GetGPA(); // m_GPA 리턴

	Subject();		// NULL 또는 0으로 초기화
	Subject(string name, int hakjum, string grade); // 입력된 인자로 초기화
	Subject(const Subject& sub); // 다른 Subject 클래스의 멤버변수의 값으로 초기화
	~Subject(); // 아직
};
#endif