/***********************************************************************
/*
		HW#4-3: 성적처리프로그램#3

작성자: 김예원									  날짜: 2021년  4월  7일

문제 정의:
성적처리프로그램#2를 다음 부분만 수정한다.
 - 메뉴 출력 함수를 인라인 함수로 변경
 - 추가 구현 함수
	- 개별 데이터 입력 함수(오버로드된 인라인 함수로 구현)
	- 전체 학생 목록 보기 함수(학번, 이름 출력)
	- 학생 정보 수정 함수

교과목 별 평점 계산
A+     A0    B+     B0    C+     C0    D+     D0    F
4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0

*/
/***********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define HOWMANYSTD 2 //입력받을 학생 수
#define HOWMANYSUB 3 //입력받을 과목 수

struct Subject {
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};
struct Student {
	char StdName[30];
	int Hakbun;
	Subject sub[HOWMANYSUB];
	float AveGPA;
};
struct _GP {
	char grade[3];
	float grade_point;
} GP[9] = {
	{"A+", 4.5},
	{"A0", 4.0},
	{"B+", 3.5},
	{"B0", 3.0},
	{"C+", 2.5},
	{"C0", 2.0},
	{"D+", 1.5},
	{"D0", 1.0},
	{"F", 0.0}
};

struct Subject sub[HOWMANYSUB];
struct Student stu[HOWMANYSTD];

inline void PrintMenu(); //메뉴 출력
inline void InputValue(char* str); //이름, 과목명, 과목 등급
inline void InputValue(int& i); //메뉴번호, 전체학생 수, 과목 수, 학번, 학점
void PrintAllStdList(Student* pSt, int StudentNum); //전체 학생 목록 보기
void ModifyStdInfo(Student* pSt); //학생 정보 수정

int get_input(struct Student* stu, struct Subject* sub); //학생 정보, 과목 정보 입력받기
void CalcGPA(Subject& Sub); //교과목의 평점 계산 함수
float CalcAveGPA(Subject* Sub); //개인 학생의 평균 평점 계산
void PrintAllData(const Student* pSt, int StudentNum); //전체 학생 정보 출력 함수
void PrintOneData(const Student& rSt); //개인 학생 정보 출력 함수
Student* StdSearch(Student* pSt, int StudentNum); //학생 이름 검색 함수

int main() {
	PrintMenu();
}

inline void PrintMenu() {
	while (1) { //무한 루프
		cout << "\n\n\n=====메뉴=====\n";
		cout << "1. 학생 성적 입력\n2. 전체 학생 성적 보기\n3. 학생 이름 검색\n4. 전체 학생 목록 보기\n5. 학생 정보 수정\n6. 프로그램 종료\n\n";

		cout << "원하는 기능을 입력하세요: ";
		int menu;
		cin >> menu;

		switch (menu) { //swith-case 문을 이용하여 메뉴 구현
		case 1: //1. 학생 성적 입력
			get_input(stu, sub);
			break;
		case 2: //2. 전체 학생 성적 보기
			int i, j;
			for (i = 0; i < HOWMANYSTD; i++) {
				for (j = 0; j < HOWMANYSUB; j++) {
					CalcGPA(stu[i].sub[j]); //i+1번째 학생의 j+1번째 교과목 평점 구하기
				}
				stu[i].AveGPA = CalcAveGPA(stu[i].sub); //교과목 평균 평점 구하기
			}
			PrintAllData(stu, HOWMANYSTD); //출력 함수 호출
			break;
		case 3: //3. 학생 이름 검색
			Student * SearchStd;
			SearchStd = StdSearch(stu, HOWMANYSTD);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd);
			}
			else {
				cout << "해당 학생의 정보가 없습니다.\n\n";
			}
			break;
		case 4: //4. 전체 학생 목록 보기
			PrintAllStdList(stu, HOWMANYSTD);
			break;
		case 5: //5. 학생 정보 수정
			Student stu[HOWMANYSTD];
			ModifyStdInfo(stu);
			break;
		case 6: //6. 프로그램 종료
			cout << "프로그램을 종료합니다.\n\n\n";
			return;
		default:
			cout << "제시 된 메뉴 중에서 골라주세요.\n";
		}
	}
}
int get_input(struct Student* stu, struct Subject* sub) {
	for (int i = 0; i < HOWMANYSTD; i++) { //학생의 이름을 HOWMANYSTD(2)회 입력 받기
		cout << "\n\n\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요\n";
		cout << "이름: ";
		InputValue(stu[i].StdName);
		cout << "학번: ";
		InputValue(stu[i].Hakbun);
		cout << "\n";

		cout << "* 수강한 과목 " << HOWMANYSUB << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (int j = 0; j < HOWMANYSUB; j++) { //i번째 학생의 교과목 정보를 HOWMANYSUB(3)회 입력 받기
			cout << "교과목명: ";
			InputValue(stu[i].sub[j].SubName);
			cout << "과목학점: ";
			InputValue(stu[i].sub[j].Hakjum);
			cout << "과목등급(A+ ~ F): ";
			InputValue(stu[i].sub[j].Grade);
			cout << "\n";
		}
	}
	return 0;
}
void CalcGPA(Subject& Sub) {
	//교과목 평점 계산
	int i;
	for (i = 0; i < 9; i++) {
		if (strcmp(Sub.Grade, GP[i].grade) == 0) {
			Sub.GPA = Sub.Hakjum * GP[i].grade_point;
		}
	}
	return;
}
float CalcAveGPA(Subject* Sub) {
	//개인 학생의 평균 평점 계산
	float GPAsum, AveGPA;
	GPAsum = 0;
	int i;
	for (i = 0; i < HOWMANYSUB; i++) {
		GPAsum += (Sub + i)->GPA;
	}
	AveGPA = GPAsum / HOWMANYSUB;
	return AveGPA;
}
void PrintAllData(const Student* pSt, int StudentNum) {
	cout.precision(2); //소수점 이하 2자리 까지만 출력하도록 고정
	cout << fixed;

	cout << "\n\t\t전체 학생 성적 보기\n";
	cout << "==================================================\n";

	int i;
	for (i = 0; i < HOWMANYSTD; i++) {
		PrintOneData(pSt[i]); //학생 각각의 데이터를 HOWMANYSTU(2)회 출력
	}
	cout << "\n";
	return;
}
void PrintOneData(const Student& rSt) {
	cout.width(10);
	cout << "이름: " << rSt.StdName;
	cout.width(10);
	cout << "학번: " << rSt.Hakbun;
	cout << "\n==================================================\n";

	cout.width(50);
	cout << right << "과목명   과목학점   과목등급   과목평점\n"; //오른쪽 정렬

	int i;
	cout << "==================================================\n";
	for (i = 0; i < HOWMANYSUB; i++) {
		cout.width(20);
		cout << right << rSt.sub[i].SubName;
		cout.width(10);
		cout << right << rSt.sub[i].Hakjum;
		cout.width(10);
		cout << right << rSt.sub[i].Grade;
		cout.width(10);
		cout << right << rSt.sub[i].GPA;
		cout << "\n";
	}
	cout << "\n==================================================\n";
	cout.width(50);
	cout << right << "평균평점 " << rSt.AveGPA << "\n\n";
	return;
}
Student* StdSearch(Student* pSt, int StudentNum) {
	char name[30];
	cout << "\n\n\n";
	cout << "검색 할 학생의 이름: ";
	cin >> name;

	int i;
	for (i = 0; i < StudentNum; i++) {
		if (strcmp(name, pSt[i].StdName) == 0) { //찾는 이름이 학생 목록에 있다면
			return &pSt[i]; //해당 학생 정보 return
		}
	}
	return NULL;
}

inline void InputValue(char* str) {
	cin >> str; //문자열을 입력 받기
}
inline void InputValue(int& i) {
	cin >> i; //정수를 입력 받기
}

void PrintAllStdList(Student* pSt, int StudentNum) {
	cout << "\n==================================================\n";
	cout.width(10);
	cout << right << "학번";
	cout.width(10);
	cout << right << "이름\n";
	cout << "==================================================\n";
	int i;
	for (i = 0; i < StudentNum; i++) {
		cout.width(10);
		cout << (pSt + i)->Hakbun; //i번째 학생의 학번 출력
		cout.width(10);
		cout << (pSt + i)->StdName; //i번째 학생의 이름 출력
		cout << "\n";
	}
	cout << "\n==================================================";
}
void ModifyStdInfo(Student* pSt) {
	pSt = StdSearch(stu, HOWMANYSTD);
	if (pSt != NULL) { //찾는 이름이 학생 목록에 있다면
		cout << "*(" << pSt->StdName << ", " << pSt->Hakbun << "의 정보를 수정하세요.\n";
		cout << "이름: ";
		InputValue(pSt->StdName); //해당 자리에 이름을 새로 초기화
		cout << "학번: ";
		InputValue(pSt->Hakbun); //해당 자리에 학번을 새로 초기화
		cout << "\n";
	}
	else {
		cout << "해당 학생의 정보가 없습니다.\n\n";
	}
	return;
}