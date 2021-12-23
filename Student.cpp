#include "Student.h"

using namespace std;

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
void Student::Modify() {
	if (this != NULL) { //찾는 이름이 학생 목록에 있다면
		string Type; //학생정보와 과목정보 중 어느것을 수정 할 것인지?

		cout << "수정(학생정보 / 과목정보 / 모두): ";
		InputValue(Type);

		if (Type == "학생정보") {
			cout << "*(" << m_name << ", " << m_hakbun << ")의 정보를 수정하세요.\n";
			cout << "이름: ";
			InputValue(m_name); //해당 자리의 이름을 새로 초기화
			cout << "학번: ";
			InputValue(m_hakbun); //해당 자리의 학번을 새로 초기화
			cout << "\n";
		}
		else if (Type == "과목정보") {
			for (int i = 0; i < m_subnum; i++) {
				m_sub[i].Modify(); // 교과목 정보 수정 함수 호출
			}
			CalcAveGPA(); // 해당 학생의 평균 평점 계산
		}
		else if (Type == "모두") {
			cout << "*(" << m_name << ", " << m_hakbun << ")의 정보를 수정하세요.\n";
			cout << "이름: ";
			InputValue(m_name); //해당 자리의 이름을 새로 초기화
			cout << "학번: ";
			InputValue(m_hakbun); //해당 자리의 학번을 새로 초기화
			cout << "\n";

			for (int i = 0; i < m_subnum; i++) {
				m_sub[i].Modify(); // 교과목 정보 수정 함수 호출
			}
			CalcAveGPA(); // 해당 학생의 평균 평점 계산
		}
	}
	else {
		cout << "해당 학생의 정보가 없습니다.\n\n";
	}
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
Student::Student() {
	cout << "Student 디폴트 생성자 호출!" << endl;
	m_name = " ";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_avgGPA = 0.0;
}
Student::Student(string name, int hakbun, int subnum, Subject* sub) {
	cout << "Student 인자있는 생성자 호출!" << endl;
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < subnum; i++) { // subnum 수만큼 for문 반복
		m_sub[i] = sub[i];
	}
	CalcAveGPA();
}
Student::Student(const Student& std) {
	cout << "Student 복사생성자 호출!" << endl;
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) { // subnum 수만큼 for문 반복
		m_sub[i] = std.m_sub[i];
	}
	m_avgGPA = std.m_avgGPA;
}
Student::~Student() {
	cout << "Student 소멸자 호출!" << endl;
	delete[] m_sub;
	m_sub = NULL;
}