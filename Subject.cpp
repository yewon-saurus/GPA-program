#include "Subject.h"
using namespace std;

struct _GP {
	string grade;
	float grade_point;
} GP[9] = {
	{"A+", 4.5},
	{"A", 4.0},
	{"B+", 3.5},
	{"B", 3.0},
	{"C+", 2.5},
	{"C", 2.0},
	{"D+", 1.5},
	{"D", 1.0},
	{"F", 0.0}
};

void Subject::Initialize() {
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
}
void Subject::Initialize(string name, int hakjum, string grade) {
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
}
inline void Subject::InputValue(int& i) {
	cin >> i; // 정수를 입력받기
	cin.ignore();
}
inline void Subject::InputValue(string& str) {
	getline(cin, str); // 문자열을 입력 받기 --> 틈새 cin.ignore();
}
void Subject::InputData() {
	cout << "교과목명: ";
	InputValue(m_name);
	cout << "과목학점: ";
	InputValue(m_hakjum);
	cout << "과목등급(A+ ~ F): ";
	InputValue(m_grade);
	cout << "\n";
	CalcGPA();
}
void Subject::PrintTitle() {
	cout.precision(2); // 소수점 이하 2자리 까지만 출력하도록 고정
	cout << fixed;

	cout << "\n==================================================" << endl;
	cout.width(50);
	cout << right << "과목명   과목학점   과목등급   과목평점" << endl; // 오른쪽 정렬
	cout << "==================================================" << endl;
}
void Subject::PrintData() {
	cout.width(20);
	cout << right << m_name;
	cout.width(10);
	cout << right << m_hakjum;
	cout.width(10);
	cout << right << m_grade;
	cout.width(10);
	cout << right << m_GPA;
	cout << endl;
}
void Subject::CalcGPA() {
	int i;
	for (i = 0; i < 9; i++) {
		if (m_grade == GP[i].grade) {
			m_GPA = m_hakjum * GP[i].grade_point;
		}
	}
}
string Subject::GetName() {
	return m_name;
}
int Subject::GetHakjum() {
	return m_hakjum;
}
string Subject::GetGrade() {
	return m_grade;
}
float Subject::GetGPA() {
	return m_GPA;
}