/**********************************************************************/
/*                                                                    */
/*       HW#1: C++ 시작하기                                           */
/* 작성자: 김예원                               날짜: 2021년 3월 12일 */
/*                                                                    */
/* 문제 정의:                                                         */
/* 학생들의 정보와 성적을 입력받아 평점을 계산하는 성적 처리 프로그램 */
/*                                                                    */
/* 교과목 별 평점 계산                                                */
/* A+     A     B+     B     C+     C     D+     D     F              */
/* 4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0            */
/*                                                                    */
/**********************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
#define HOWMANYSTD 2 //입력받을 학생 수
#define HOWMANYSUB 3 //입력받을 과목 수

int get_input(struct Student* stu, struct Subject* sub); //학생 정보, 과목 정보 입력받기
int calc(struct Student* stu, struct Subject* sub); //계산
int print(struct Student* stu, struct Subject* sub); //출력

struct Subject {
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};

struct Student {
	char StdName[30];
	int Hakbun;
	Subject sub[3];
	float AveGPA;
};

struct Subject sub[HOWMANYSUB];
struct Student stu[HOWMANYSTD];

int main(void) {
	while (1) { //무한 루프
		cout << "=====메뉴=====\n";
		cout << "1. 학생 성적 입력\n2. 전체 학생 성적보기\n3. 프로그램 종료\n\n";

		cout << "원하는 기능을 입력하세요: ";
		int menu;
		cin >> menu;

		switch (menu) { //swith-case 문을 이용하여 메뉴 구현
		case 1:
			get_input(stu, sub); //입력 함수 호출
			break;
		case 2:
			calc(stu, sub); //계산 함수 호출
			print(stu, sub); //출력 함수 호출
			break;
		case 3:
			cout << "\n프로그램을 종료합니다.";
			return 0;
		default:
			cout << "1, 2, 3 번 중에서 골라야 해요.";
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
int calc(struct Student* stu, struct Subject* sub) {
	float GPAsum;

	//교과목 평점 계산
	//3학점 교과목으로 A+의 경우 3X4.5=13.5
	int i, j;
	for (i = 0; i < HOWMANYSTD; i++) {
		GPAsum = 0;
		for (j = 0; j < HOWMANYSUB; j++) {
			if (stu[i].sub[j].Hakjum == 3) { //만약 과목 학점이 3점 이면서
				if (strcmp(stu[i].sub[j].Grade, "A+") == 0) { //등급이 A+라면
					stu[i].sub[j].GPA = 3 * 4.5; //GPA(해당 과목의 평점) = 3(학점) * 4.5(A+등급)
				}
				else if (strcmp(stu[i].sub[j].Grade, "A") == 0) {
					stu[i].sub[j].GPA = 3 * 4.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "B+") == 0) {
					stu[i].sub[j].GPA = 3 * 3.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "B") == 0) {
					stu[i].sub[j].GPA = 3 * 3.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "C+") == 0) {
					stu[i].sub[j].GPA = 3 * 2.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "C") == 0) {
					stu[i].sub[j].GPA = 3 * 2.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "D+") == 0) {
					stu[i].sub[j].GPA = 3 * 1.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "D") == 0) {
					stu[i].sub[j].GPA = 3 * 1.0;
				}
				else {
					stu[i].sub[j].GPA = 3 * 0.0;
				}
			}
			else { //만약 학점이 2점 이라면..
				if (strcmp(stu[i].sub[j].Grade, "A+") == 0) {
					stu[i].sub[j].GPA = 2 * 4.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "A") == 0) {
					stu[i].sub[j].GPA = 2 * 4.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "B+") == 0) {
					stu[i].sub[j].GPA = 2 * 3.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "B") == 0) {
					stu[i].sub[j].GPA = 2 * 3.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "C+") == 0) {
					stu[i].sub[j].GPA = 2 * 2.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "C") == 0) {
					stu[i].sub[j].GPA = 2 * 2.0;
				}
				else if (strcmp(stu[i].sub[j].Grade, "D+") == 0) {
					stu[i].sub[j].GPA = 2 * 1.5;
				}
				else if (strcmp(stu[i].sub[j].Grade, "D") == 0) {
					stu[i].sub[j].GPA = 2 * 1.0;
				}
				else {
					stu[i].sub[j].GPA = 2 * 0.0;
				}
			}
			GPAsum += stu[i].sub[j].GPA;
			stu[i].AveGPA = GPAsum / 3; //개인 학생의 교과목 평균 평점 = 해당 학생의 모든 평점의 / 3
		}
	}
	return 0;
}
int print(struct Student* stu, struct Subject* sub) {
	cout.precision(2); //소수점 이하 2자리만 출력하도록 고정
	cout << fixed;

	cout << "\n\t\t전체 학생 성적 보기";
	cout << "\n==================================================";

	int i, j;
	for (i = 0; i < HOWMANYSTD; i++) {
		cout.width(10);
		cout << "\n이름: " << stu[i].StdName;
		cout.width(10);
		cout << "학번: " << stu[i].Hakbun;
		cout << "\n==================================================\n";

		cout.width(50);
		cout << right << "과목명   과목학점   과목등급   과목평점"; //오른쪽 정렬
		cout << "\n==================================================\n";
		for (j = 0; j < HOWMANYSUB; j++) {
			cout.width(20);
			cout << right << stu[i].sub[j].SubName;
			cout.width(10);
			cout << right << stu[i].sub[j].Hakjum;
			cout.width(10);
			cout << right << stu[i].sub[j].Grade;
			cout.width(10);
			cout << right << stu[i].sub[j].GPA << "\n";
		}
		cout << "\n==================================================\n";
		cout.width(50);
		cout << right << "평균평점 " << stu[i].AveGPA;
		cout << "\n";
	}
	cout << "\n";
	return 0;
}