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
void Subject::Modify() {
	if (this != NULL) {
		cout << "*(" << m_name << ", 학점: " << m_hakjum << ", 등급: " << m_grade << ")의 정보를 수정하세요.\n";
		cout << "교과목명: ";
		InputValue(this->m_name); //해당 자리의 교과목 이름을 새로 초기화
		cout << "과목학점: ";
		InputValue(this->m_hakjum); //해당 자리의 교과목 학점을 새로 초기화
		cout << "과목등급: ";
		InputValue(this->m_grade); //해당 자리의 교과목 등급을 새로 초기화
		cout << "\n";

		this->CalcGPA();	//과목의 등급과 학점수가 바뀌면 평점도 바뀐다
	}
	else {
		cout << "해당 과목의 정보가 없습니다.\n\n";
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
Subject::Subject() {
	cout << "Subject 디폴트 생성자 호출!" << endl;
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0;
};
Subject::Subject(string name, int hakjum, string grade) {
	cout << "Subject 인자있는 생성자 호출!" << endl;
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
}
Subject::Subject(const Subject& sub) {
	cout << "Subject 복사생성자 호출!" << endl;
	m_name = sub.m_name; // m_name 복사
	m_hakjum = sub.m_hakjum; // m_hakjum 복사
	m_grade = sub.m_grade; // m_grade 복사
	m_GPA = sub.m_GPA; // m_GPA 복사
}
Subject::~Subject() {
	cout << "Subject 소멸자 호출!" << endl;
}