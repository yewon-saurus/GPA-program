#include "Student.h"

using namespace std;

void Student::Initialize() {
	m_name = " ";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_avgGPA = 0;
}
void Student::Initialize(string name, int hakbun, int subnum, Subject* sub) {
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = sub;
}
void Student::Remove() {
	delete[] m_sub;
}
inline void Student::InputValue(int& i) {
	cin >> i; // 정수를 입력받기
	cin.ignore();
}
inline void Student::InputValue(string& str) {
	getline(cin, str);
}
void Student::InputData() {
	cout << "이름: ";
	InputValue(m_name);
	cout << "학번: ";
	InputValue(m_hakbun);

	cout << "\n수강한 과목 수를 입력: ";
	InputValue(m_subnum);
	m_sub = new Subject[m_subnum];

	cout << "\n* 수강한 과목 " << m_subnum << "개의 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
	for (int i = 0; i < m_subnum; i++) {
		(m_sub + i)->InputData();
	}
	CalcAveGPA();
}
void Student::PrintData() {
	cout.width(10);
	cout << "이름: " << m_name;
	cout.width(10);
	cout << "학번: " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\n==================================================" << endl;
	cout.width(50);
	cout << right << "평균평점 " << m_avgGPA << endl;
}
void Student::CalcAveGPA() {
	float GPAsum;
	GPAsum = 0;
	for (int i = 0; i < m_subnum; i++) {
		GPAsum += (m_sub + i)->GetGPA();
	}
	m_avgGPA = GPAsum / m_subnum;
}
string Student::GetName() {
	return m_name;
}
int Student::GetHakbun() {
	return m_hakbun;
}
int Student::GetSubNum() {
	return m_subnum;
}
float Student::GetAveGPA() {
	return m_avgGPA;
}