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
	void Initialize();						// 멤버변수 초기화 --> 과목명: " ", 학점: 0, 등급: " "
	void Initialize(string name, int hakjum, string grade);   // 인자값으로 멤버변수 초기화
	void InputValue(int& i);
	void InputValue(string& str);
	void InputData();	// 멤버변수 값 입력(with InputValue)
	void PrintTitle();
	void PrintData();
	void CalcGPA();

	string GetName(); // m_name 리턴
	int GetHakjum(); // m_hakjum 리턴
	string GetGrade(); // m_grade 리턴
	float GetGPA(); // m_GPA 리턴
};
#endif