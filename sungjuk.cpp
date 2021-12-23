/***********************************************************************/
/*                                                                     */
/*       HW#3: 구조체, 레퍼런스 함수인자전달 실습                      */
/* 작성자: 김예원                               날짜: 2021년 3월 26일  */
/*                                                                     */
/* 문제 정의:                                                          */
/* 학생들의 정보와 성적을 입력받아 평점을 계산하는 성적 처리 프로그램  */
/* 실습 1에서 만든 프로그램을 다음과 같이 개선한다.                    */
/*                                                                     */
/* 메뉴 출력 함수, 평점 계산 함수, 교과목 평점 계산 함수, 전체 학생    */
/* 정보 출력 함수, 개인 학생 정보 출력 함수, 학생 이름 검색 함수 추가  */
/*                                                                     */
/* 교과목 별 평점 계산                                                 */
/* A+     A0    B+     B0    C+     C0    D+     D0    F               */
/* 4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0             */
/*                                                                     */
/***********************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
#define HOWMANYSTD 2 //입력받을 학생 수
#define HOWMANYSUB 3 //입력받을 과목 수

void PrintMenu(); //메뉴 출력 함수
int get_input(struct Student* stu, struct Subject* sub); //학생 정보, 과목 정보 입력받기
void CalcGPA(Subject& Sub); //교과목의 평점 계산 함수
float CalcAveGPA(Subject* Sub); //개인 학생의 평균 평점 계산
void PrintAllData(const Student* pSt, int StudentNum); //전체 학생 정보 출력 함수
void PrintOneData(const Student& rSt); //개인 학생 정보 출력 함수
Student* StdSearch(Student* pSt, int StudentNum); //학생 이름 검색 함수

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

struct Subject sub[HOWMANYSUB];
struct Student stu[HOWMANYSTD];

int main() {
	PrintMenu();
}

void PrintMenu() {
	while (1) { //무한 루프
		cout << "\n\n\n=====메뉴=====\n";
		cout << "1. 학생 성적 입력\n2. 전체 학생 성적 보기\n3. 학생 이름 검색\n4. 프로그램 종료\n\n";

		cout << "원하는 기능을 입력하세요: ";
		int menu;
		cin >> menu;

		switch (menu) { //swith-case 문을 이용하여 메뉴 구현
		case 1:
			get_input(stu, sub); //입력 함수 호출
			break;
		case 2:
			int i, j;
			for (i = 0; i < HOWMANYSTD; i++) {
				for (j = 0; j < HOWMANYSUB; j++) {
					CalcGPA(stu[i].sub[j]); //i+1번째 학생의 j+1번째 교과목 평점 구하기
				}
				stu[i].AveGPA = CalcAveGPA(stu[i].sub); //교과목 평균 평점 구하기
			}
			PrintAllData(stu, HOWMANYSTD); //출력 함수 호출
			break;
		case 3:
			Student* SearchStd;
			SearchStd = StdSearch(stu, HOWMANYSTD);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd);
			}
			else {
				cout << "해당 학생의 정보가 없습니다.\n\n";
			}
			break;
		case 4:
			cout << "\n프로그램을 종료합니다.\n\n\n";
			return;
		default:
			cout << "1, 2, 3, 4 번 중에서 골라야 해요.";
		}
	}
}
int get_input(struct Student* stu, struct Subject* sub) {
	for (int i = 0; i < HOWMANYSTD; i++) { //학생의 이름을 HOWMANYSTD(2)회 입력 받기
		cout << "\n\n\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요\n";
		cout << "이름: ";
		cin >> stu[i].StdName;
		cout << "학번: ";
		cin >> stu[i].Hakbun;
		cout << "\n";

		cout << "* 수강한 과목 " << HOWMANYSUB << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (int j = 0; j < HOWMANYSUB; j++) { //i번째 학생의 교과목 정보를 HOWMANYSUB(3)회 입력 받기
			cout << "교과목명: ";
			cin >> stu[i].sub[j].SubName;
			cout << "과목학점: ";
			cin >> stu[i].sub[j].Hakjum;
			cout << "과목등급(A+ ~ F): ";
			cin >> stu[i].sub[j].Grade;
			cout << "\n";
		}
	}
	return 0;
}
void CalcGPA(Subject& Sub) {
	//교과목 평점 계산
	//3학점 교과목으로 A+의 경우 3X4.5=13.5
	if (Sub.Hakjum == 3) { //만약 교과목 학점이 3점 이면서
		if (strcmp(Sub.Grade, "A+") == 0) { //등급이 A+ 라면
			Sub.GPA = 3 * 4.5; //GPA(해당 과목의 평점) = 3(학점) * 4.5(A+등급)
		}
		else if (strcmp(Sub.Grade, "A0") == 0) {
			Sub.GPA = 3 * 4.0;
		}
		else if (strcmp(Sub.Grade, "B+") == 0) {
			Sub.GPA = 3 * 3.5;
		}
		else if (strcmp(Sub.Grade, "B0") == 0) {
			Sub.GPA = 3 * 3.0;
		}
		else if (strcmp(Sub.Grade, "C+") == 0) {
			Sub.GPA = 3 * 2.5;
		}
		else if (strcmp(Sub.Grade, "C0") == 0) {
			Sub.GPA = 3 * 2.0;
		}
		else if (strcmp(Sub.Grade, "D+") == 0) {
			Sub.GPA = 3 * 1.5;
		}
		else if (strcmp(Sub.Grade, "D0") == 0) {
			Sub.GPA = 3 * 1.0;
		}
		else {
			Sub.GPA = 0;
		}
	}
	else { //만약 교과목 학점이 2점 이면서..
		if (strcmp(Sub.Grade, "A+") == 0) {
			Sub.GPA = 2 * 4.5;
		}
		else if (strcmp(Sub.Grade, "A0") == 0) {
			Sub.GPA = 2 * 4.0;
		}
		else if (strcmp(Sub.Grade, "B+") == 0) {
			Sub.GPA = 2 * 3.5;
		}
		else if (strcmp(Sub.Grade, "B0") == 0) {
			Sub.GPA = 2 * 3.0;
		}
		else if (strcmp(Sub.Grade, "C+") == 0) {
			Sub.GPA = 2 * 2.5;
		}
		else if (strcmp(Sub.Grade, "C0") == 0) {
			Sub.GPA = 2 * 2.0;
		}
		else if (strcmp(Sub.Grade, "D+") == 0) {
			Sub.GPA = 2 * 1.5;
		}
		else if (strcmp(Sub.Grade, "D0") == 0) {
			Sub.GPA = 2 * 1.0;
		}
		else {
			Sub.GPA = 0;
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
	cout.precision(2); //소수점 이하 2자리만 출력하도록 고정
	cout << fixed;

	cout << "\n\t\t전체 학생 성적 보기";
	cout << "\n==================================================";

	int i;
	for (i = 0; i < HOWMANYSTD; i++) {
		PrintOneData(pSt[i]); //학생 각각의 데이터를 HOWMANYSTU(2)회 출력
	}
	cout << "\n";
	return;
}
void PrintOneData(const Student& rSt) {
	cout.width(10);
	cout << "\n이름: " << rSt.StdName;
	cout.width(10);
	cout << "학번: " << rSt.Hakbun;
	cout << "\n==================================================\n";

	cout.width(50);
	cout << right << "과목명   과목학점   과목등급   과목평점"; //오른쪽 정렬

	int i;
	cout << "\n==================================================\n";
	for (i = 0; i < HOWMANYSUB; i++) {
		cout.width(20);
		cout << right << rSt.sub[i].SubName;
		cout.width(10);
		cout << right << rSt.sub[i].Hakjum;
		cout.width(10);
		cout << right << rSt.sub[i].Grade;
		cout.width(10);
		cout << right << rSt.sub[i].GPA << "\n";
	}
	cout << "\n==================================================\n";
	cout.width(50);
	cout << right << "평균평점 " << rSt.AveGPA;
	cout << "\n";
	return;
}
Student* StdSearch(Student* pSt, int StudentNum) {
	char name[30];
	cout << "\n\n\n";
	cout << "검색 할 학생의 이름: ";
	cin >> name;
	
	int i;
	for (i = 0; i < StudentNum; i++) {
		if (strcmp(name, pSt[i].StdName) == 0) {
			return &pSt[i];
		}
	}
	return NULL;
}