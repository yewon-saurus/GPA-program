#include "GradeManager.h"
using namespace std;

GradeManager::GradeManager() {
	m_std = NULL;
	m_stdnum = 0;
	cout << "GradeManager 디폴트 생성자 호출!" << endl;
}
GradeManager::GradeManager(int m_stdnum) {
	this->m_stdnum = m_stdnum;
	m_std = new Student[m_stdnum];
	cout << "GradeManager 인자있는 생성자 호출!" << endl;
}
GradeManager::~GradeManager() {
	delete[] m_std;
	m_std = NULL;
	cout << "GradeManager 소멸자 호출!" << endl;
}
void GradeManager::Execute() {
	while (1) // 무한 루프
	{
		PrintMenu();

		int menu;
		InputUtil::InputValue(menu);

		switch (menu) {
		case 1: // 1. 학생 성적 입력
		{
			cout << "\n몇 명의 정보를 입력하시겠습니까?: ";
			InputUtil::InputValue(m_stdnum);
			GradeManager(m_stdnum);
			m_std->InputData();
			break;
		}
		case 2: // 2. 전체 성적 보기
			for (int i = 0; i < m_stdnum; i++) {
				m_std[i].PrintData();
			}
			break;
		case 3: // 3. 학생 검색
			Student * SearchStd;
			SearchStd = StdSearch(m_std->GetName());
			if (SearchStd != NULL) {
				m_std->PrintData();
			}
			else {
				cout << "해당 학생의 정보가 없습니다." << endl;
			}
			break;
		case 4: // 4. 학생 목록 보기
			PrintAllStdList();
			break;
		case 5: // 5. 학생 정보 수정
			Modify();
			break;
		case 6: // 6. 프로그램 종료
			cout << "프로그램을 종료합니다." << endl;
			return;
		default:
			cout << "제시 된 메뉴 중에서 골라주세요!" << endl;
		}
	}
}
void GradeManager::PrintMenu() {
	cout << endl;
	cout << "===== 메뉴 =====" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 성적 보기" << endl;
	cout << "3. 학생 검색" << endl;
	cout << "4. 학생 목록 보기" << endl;
	cout << "5. 학생 정보 수정" << endl;
	cout << "6. 프로그램 종료" << endl;
	cout << endl;
	cout << "원하는 기능을 입력하세요(번호입력) : ";
}
Student* GradeManager::StdSearch(string stdname) const {
	cout << "\n\n";
	cout << "검색 할 학생의 이름: ";
	InputUtil::InputValue(stdname);

	int i;
	for (i = 0; i < m_stdnum; i++) {
		if (stdname == m_std[i].GetName()) { // 찾는 이름이 학생 목록에 있다면
			return &m_std[i]; // 해당 학생 정보 return
		}
	}
	return NULL;
}
void GradeManager::PrintAllStdList() const {
	cout << "\n==================================================\n";
	cout.width(10);
	cout << right << "학번";
	cout.width(10);
	cout << right << "이름\n";
	cout << "==================================================\n";
	int i;
	for (i = 0; i < m_stdnum; i++) {
		cout.width(10);
		cout << m_std[i].GetHakbun(); // i번째 학생의 학번 출력
		cout.width(10);
		cout << m_std[i].GetName(); // i번째 학생의 이름 출력
		cout << "\n";
	}
	cout << "\n==================================================";
}
void GradeManager::Modify() {
	Student* St = StdSearch(m_std->GetName());
	m_std->Modify();
}