#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>
#include "IOInterface.h"

using namespace std;
class Subject : public IOInterface {
protected:
	int m_hakjum;
	string m_grade;
	float m_GPA;

public:
	void InputData();	// 멤버변수 값 입력(with InputValue)
	static void PrintTitle();
	void PrintData() const;
	void CalcGPA();
	void Modify();

	int GetHakjum() const; // m_hakjum 리턴
	string GetGrade() const; // m_grade 리턴
	float GetGPA() const; // m_GPA 리턴

	Subject();		// NULL 또는 0으로 초기화
	Subject(string name, int hakjum, string grade); // 입력된 인자로 초기화
	Subject(const Subject& sub); // 다른 Subject 클래스의 멤버변수의 값으로 초기화
	~Subject(); // 아직
};
#endif