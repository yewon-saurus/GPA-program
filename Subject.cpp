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

void Subject::InputData() {
	cout << "교과목명: ";
	InputUtil::InputValue(m_name);
	cout << "과목학점: ";
	InputUtil::InputValue(m_hakjum);
	cout << "과목등급(A+ ~ F): ";
	InputUtil::InputValue(m_grade);
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
void Subject::PrintData() const {
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
void Subject::Modify() {
	if (this != NULL) {
		cout << "*(" << m_name << ", 학점: " << m_hakjum << ", 등급: " << m_grade << ")의 정보를 수정하세요.\n";
		cout << "교과목명: ";
		InputUtil::InputValue(this->m_name); //해당 자리의 교과목 이름을 새로 초기화
		cout << "과목학점: ";
		InputUtil::InputValue(this->m_hakjum); //해당 자리의 교과목 학점을 새로 초기화
		cout << "과목등급: ";
		InputUtil::InputValue(this->m_grade); //해당 자리의 교과목 등급을 새로 초기화
		cout << "\n";

		this->CalcGPA();	//과목의 등급과 학점수가 바뀌면 평점도 바뀐다
	}
	else {
		cout << "해당 과목의 정보가 없습니다.\n\n";
	}
}
int Subject::GetHakjum() const {
	return m_hakjum;
}
string Subject::GetGrade() const {
	return m_grade;
}
float Subject::GetGPA() const {
	return m_GPA;
}
Subject::Subject() {
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0;
	cout << "Subject 디폴트 생성자 호출!" << endl;
};
Subject::Subject(string name, int hakjum, string grade) : IOInterface(name) {
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
	m_data = 100;
	cout << "Subject 인자있는 생성자 호출!" << endl;
}
Subject::Subject(const Subject& sub) {
	m_name = sub.m_name; // m_name 복사
	m_hakjum = sub.m_hakjum; // m_hakjum 복사
	m_grade = sub.m_grade; // m_grade 복사
	m_GPA = sub.m_GPA; // m_GPA 복사
	cout << "Subject 복사생성자 호출!" << endl;
}
Subject::~Subject() {
	cout << "Subject 소멸자 호출!" << endl;
}