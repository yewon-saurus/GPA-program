/***********************************************************************/
/*
		HW#6: 성적처리프로그램#5

작성자: 김예원									  날짜: 2021년  4월  23일

문제 정의:
성적처리프로그램#3을 다음 부분만 수정한다.
 - 문자 배열로 사용했던 데이터타입(학생 이름, 과목 이름)을 string으로
   변경한다.
   -> 앞으로 모든 문자열은 string을 사용
 - 문자열 입력함수 getline()을 사용하여 문자열 입력하도록 수정
 - 학생 정보 수정하는 함수 수정
   -> 기존의 학생의 이름과 학번만을 수정할 수 있었던 ModifyStdInfo() 함수
      를 수정하여 과목명, 학점 수, 등급도 수정할 수 있도록 확장
 - 특정 과목을 검색하는 함수 추가
   -> 과목 명을 입력하여 해당 과목이 있는지 검색

교과목 별 평점 계산
A+     A0    B+     B0    C+     C0    D+     D0    F
4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0

*/
/***********************************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Subject {
	string SubName; //string
	int Hakjum;
	string Grade;
	float GPA;
};
struct Student {
	string StdName;
	int Hakbun;
	Subject* sub;
	int SubNum; //과목 수 --> 동적으로 할당하기 위해
	float AveGPA;
};
struct _GP {
	string grade;
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

int StdNum;
int SubNum;

struct Subject* sub = NULL;
struct Student* stu = NULL;

inline void PrintMenu(); //메뉴 출력
inline void InputValue(string& str); //문자열 타입 데이터 입력 --> 이름, 과목명, 과목 등급
inline void InputValue(int& i); //정수형 데이터 입력 --> 메뉴번호, 전체학생 수, 과목 수, 학번, 학점
void PrintAllStdList(Student* pSt, int StudentNum); //전체 학생 목록 보기
void ModifyStdInfo(Student* pSt); //학생 정보 수정

void InputData(Student* stu, int StudentNum); //학생 정보, 과목 정보 입력받기 --> (추가)몇 명, 몇 개 입력받을지 동적으로 할당하기
void CalcGPA(Subject& Sub); //교과목의 평점 계산 함수
float CalcAveGPA(Subject* Sub, int SubNum); //개인 학생의 평균 평점 계산
void PrintAllData(const Student* pSt, int StudentNum); //전체 학생 정보 출력 함수
void PrintOneData(const Student& rSt); //개인 학생 정보 출력 함수

Student* StdSearch(Student* pSt, int StudentNum); //학생 이름 검색 함수
Subject* SubSearch(const Student* pSt); //과목 이름 검색 함수

int main() {
	PrintMenu();
	delete[] stu->sub;
	delete[] stu;
}

inline void PrintMenu() {
	while (1) { //무한 루프
		cout << "\n\n\n=====메뉴=====\n";
		cout << "1. 학생 성적 입력\n2. 전체 학생 성적 보기\n3. 학생 이름 검색\n4. 전체 학생 목록 보기\n5. 학생 정보 수정\n6. 프로그램 종료\n\n";

		cout << "원하는 기능을 입력하세요: ";
		int menu;
		InputValue(menu);

		switch (menu) { //swith-case 문을 이용하여 메뉴 구현
		case 1: //1. 학생 성적 입력
		{
			cout << "\n몇 명의 정보를 입력하시겠습니까?: ";
			InputValue(StdNum);
			cin.ignore();
			stu = new Student[StdNum]; //학생 StdNum명 만큼 메모리를 동적 할당
			InputData(stu, StdNum);
			break;
		}
		case 2: //2. 전체 학생 성적 보기
			PrintAllData(stu, StdNum); //출력 함수 호출
			break;
		case 3: //3. 학생 이름 검색
			Student * SearchStd;
			SearchStd = StdSearch(stu, StdNum);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd);
			}
			else {
				cout << "해당 학생의 정보가 없습니다.\n\n";
			}
			break;
		case 4: //4. 전체 학생 목록 보기
			PrintAllStdList(stu, StdNum);
			break;
		case 5: //5. 학생 정보 & 과목 정보 수정
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
void InputData(Student* stu, int StudentNum) {
	int i, j;
	for (i = 0; i < StudentNum; i++) {
		cout << "\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		// 이름 입력
		cout << "이름: ";
		InputValue((stu[i]).StdName);
		// 학번 입력
		cout << "학번: ";
		InputValue(stu[i].Hakbun);

		cout << "\n수강한 과목 수를 입력: ";
		InputValue(stu[i].SubNum);
		stu[i].sub = new Subject[(stu + i)->SubNum]; //i + 1번째 학생의 과목 수를 SubNum개 만큼 동적 할당
		cin.ignore();

		cout << "\n* 수강한 과목 " << stu[i].SubNum << "개의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (j = 0; j < stu[i].SubNum; j++) { //i번째 학생의 교과목 정보를 SubNum회 입력 받기
			cout << "교과목명: ";
			InputValue(stu[i].sub[j].SubName);
			cout << "과목학점: ";
			InputValue(stu[i].sub[j].Hakjum);
			cin.ignore();
			cout << "과목등급(A+ ~ F): ";
			InputValue(stu[i].sub[j].Grade);
			cout << "\n";

			CalcGPA(stu[i].sub[j]); //i+1번째 학생의 j+1번째 교과목 평점 구하기
		}
		stu[i].AveGPA = CalcAveGPA(stu[i].sub, stu[i].SubNum); //교과목 평균 평점 구하기
	}
	return;
}
void CalcGPA(Subject& Sub) {
	//교과목 평점 계산
	int i;
	for (i = 0; i < 9; i++) {
		if (Sub.Grade == GP[i].grade) {
			Sub.GPA = Sub.Hakjum * GP[i].grade_point;
		}
	}
	return;
}
float CalcAveGPA(Subject* Sub, int SubNum) {
	//개인 학생의 평균 평점 계산
	float GPAsum, AveGPA;
	GPAsum = 0;
	int i;
	for (i = 0; i < SubNum; i++) {
		GPAsum += (Sub + i)->GPA;
	}
	AveGPA = GPAsum / SubNum;
	return AveGPA;
}
void PrintAllData(const Student* pSt, int StudentNum) {
	cout << "\n\t\t전체 학생 성적 보기\n";
	cout << "==================================================\n";

	int i;
	for (i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]); //학생 각각의 데이터를 StudentNum회 출력
	}
	cout << "\n";
	return;
}
void PrintOneData(const Student& rSt) {
	cout.precision(2); //소수점 이하 2자리 까지만 출력하도록 고정
	cout << fixed;

	cout.width(10);
	cout << "이름: " << rSt.StdName;
	cout.width(10);
	cout << "학번: " << rSt.Hakbun;
	cout << "\n==================================================\n";

	cout.width(50);
	cout << right << "과목명   과목학점   과목등급   과목평점\n"; //오른쪽 정렬

	int i;
	cout << "==================================================\n";
	for (i = 0; i < rSt.SubNum; i++) {
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
	string name;
	cout << "\n\n\n";
	cout << "검색 할 학생의 이름: ";
	cin.ignore();
	InputValue(name);

	int i;
	for (i = 0; i < StudentNum; i++) {
		if (name == pSt[i].StdName) { //찾는 이름이 학생 목록에 있다면
			return &pSt[i]; //해당 학생 정보 return
		}
	}
	return NULL;
}
Subject* SubSearch(const Student* pSt) {
	string subName;
	cout << "\n\n\n";
	cout << "검색 할 과목의 이름: ";
	InputValue(subName);

	int i;
	for (i = 0; i < pSt->SubNum; i++) {
		if (subName == pSt->sub[i].SubName) { //찾는 이름이 학생 목록에 있다면
			return &pSt->sub[i]; //해당 학생 정보 return
		}
	}
	return NULL;
}

inline void InputValue(string& str) {
	getline(cin, str); //문자열을 입력 받기
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
	Student* St = StdSearch(pSt, StdNum);
	if (St != NULL) { //찾는 이름이 학생 목록에 있다면
		string Type; //학생정보와 과목정보 중 어느것을 수정 할 것인지?

		cout << "수정(학생정보 / 과목정보): ";
		InputValue(Type);

		if (Type == "학생정보") {
			cout << "*(" << pSt->StdName << ", " << pSt->Hakbun << ")의 정보를 수정하세요.\n";
			cout << "이름: ";
			InputValue(pSt->StdName); //해당 자리의 이름을 새로 초기화
			cout << "학번: ";
			InputValue(pSt->Hakbun); //해당 자리의 학번을 새로 초기화
			cout << "\n";
		}
		else if (Type == "과목정보") {
			Subject* Sub = SubSearch(pSt); //찾는 과목이 과목 목록에 있다면
			if (Sub != NULL) {
				cout << "*(" << pSt->sub->SubName << ", 학점: " << pSt->sub->Hakjum << ", 등급: " << pSt->sub->Grade << ")의 정보를 수정하세요.\n";
				cout << "교과목명: ";
				InputValue(pSt->sub->SubName); //해당 자리의 교과목 이름을 새로 초기화
				cout << "과목학점: ";
				InputValue(pSt->sub->Hakjum); //해당 자리의 교과목 학점을 새로 초기화
				cin.ignore();
				cout << "과목등급: ";
				InputValue(pSt->sub->Grade); //해당 자리의 교과목 등급을 새로 초기화
				cout << "\n";

				CalcGPA(*pSt->sub); //과목의 등급과 학점수가 바뀌면 평점도 바뀐다
				pSt->AveGPA = CalcAveGPA(pSt->sub, pSt->SubNum); //해당 학생의 평균 평점 계산
			}
			else {
				cout << "해당 과목의 정보가 없습니다.\n\n";
			}
		}
	}
	else {
		cout << "해당 학생의 정보가 없습니다.\n\n";
	}
	return;
}