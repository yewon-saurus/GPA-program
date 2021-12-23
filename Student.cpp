#include "Student.h"

using namespace std;

void Student::InputData() {
	cout << "이름: ";
	InputUtil::InputValue(m_name);
	cout << "학번: ";
	InputUtil::InputValue(m_hakbun);

	cout << "\n수강한 과목 수를 입력: ";
	InputUtil::InputValue(m_subnum);
	m_sub = new Subject[m_subnum];

	cout << "\n* 수강한 과목 " << m_subnum << "개의 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
	for (int i = 0; i < m_subnum; i++) {
		(m_sub + i)->InputData();
	}
	CalcAveGPA();
}
void Student::PrintData() const{
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
		InputUtil::InputValue(Type);

		if (Type == "학생정보") {
			cout << "*(" << m_name << ", " << m_hakbun << ")의 정보를 수정하세요.\n";
			cout << "이름: ";
			InputUtil::InputValue(m_name); //해당 자리의 이름을 새로 초기화
			cout << "학번: ";
			InputUtil::InputValue(m_hakbun); //해당 자리의 학번을 새로 초기화
			cout << "\n";
		}
		else if (Type == "과목정보") {
			Subject* Sub = SubSearch(m_sub->GetName());
			if (Sub != NULL) { // 찾는 과목이 있으면
				m_sub->Modify(); // 해당 과목 수정
				cout << "\n";

				m_sub->CalcGPA(); // 평점도 새로 계산
				CalcAveGPA(); //과목의 등급과 학점수가 바뀌면 평점도 바뀐다
			}
			else {
				cout << "해당 과목의 정보가 없습니다.\n\n";
			}
		}
		else if (Type == "모두") {
			cout << "*(" << m_name << ", " << m_hakbun << ")의 정보를 수정하세요.\n";
			cout << "이름: ";
			InputUtil::InputValue(m_name); //해당 자리의 이름을 새로 초기화
			cout << "학번: ";
			InputUtil::InputValue(m_hakbun); //해당 자리의 학번을 새로 초기화
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
Subject* Student::SubSearch(string subname) const {
	string thisSub;
	cout << "\n\n";
	cout << "검색 할 과목의 이름: ";
	InputUtil::InputValue(thisSub);

	for (int i = 0; i < m_subnum; i++) {
		if (subname == m_sub[i].GetName()) { // 찾는 이름이 학생 목록에 있다면
			return &m_sub[i]; // 해당 과목 정보 return
		}
	}
	cout << "찾으시는 교과목이 없습니다.";
	return NULL;
}
string Student::GetName() const {
	return m_name;
}
int Student::GetHakbun() const {
	return m_hakbun;
}
int Student::GetSubNum() const {
	return m_subnum;
}
float Student::GetAveGPA() const{
	return m_avgGPA;
}
Student::Student() {
	m_name = " ";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_avgGPA = 0.0;
	cout << "Student 디폴트 생성자 호출!" << endl;
}
Student::Student(string name, int hakbun, int subnum, Subject* sub) {
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < subnum; i++) { // subnum 수만큼 for문 반복
		m_sub[i] = sub[i];
	}
	CalcAveGPA();
	cout << "Student 인자있는 생성자 호출!" << endl;
}
Student::Student(const Student& std) {
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++) { // subnum 수만큼 for문 반복
		m_sub[i] = std.m_sub[i];
	}
	m_avgGPA = std.m_avgGPA;
	cout << "Student 복사생성자 호출!" << endl;
}
Student::~Student() {
	delete[] m_sub;
	m_sub = NULL;
	cout << "Student 소멸자 호출!" << endl;
}