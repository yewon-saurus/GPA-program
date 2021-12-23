/***********************************************************************/
/*
		HW#9: 성적처리프로그램#2 - 생성자와 소멸자

작성자: 김예원									  날짜: 2021년  5월  14일

문제 정의:
  Subject, Student Class에 Modify() 멤버함수 추가
	- 화면에서 입력되는 데이터로 Subject Class의 멤버함수 값 수정
	- 멤버변수가 수정되면 평점이 재계산되어야 함

교과목 별 평점 계산
A+     A     B+     B     C+     C     D+     D     F
4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0

*/
/***********************************************************************/
#include "Student.h"
using namespace std;

int main() {
	Subject sub1("컴퓨터", 3, "C");
	Subject sub2(sub1); // 복사생성자를 통한 초기화
	cout << "\n" << "sub1 정보" << endl;
	sub1.PrintData();
	cout << "\n" << "sub2 정보" << endl;
	sub2.PrintData();
	sub2.Modify();

	// sub2 수정 후 재확인
	cout << "\n" << "sub1 정보" << endl;
	sub1.PrintData();
	cout << "\n" << "sub2 정보" << endl;
	sub2.PrintData();

	Student st2("홍길동", 2013909845, 1, &sub1);
	Student st3("김성령", 2015909845, 1, &sub2);

	Student st1 = st2; // st1을 st2로 초기화

	cout << "\n" << "st1 정보" << endl;
	st1.PrintData();
	cout << "\n" << "st2 정보" << endl;
	st2.PrintData();
	st2.Modify();

	cout << "\n" << "수정된 st2 정보" << endl;
	st2.PrintData();
	st1.PrintData();
	cout << "\n" << "st3 정보" << endl;
	st3.PrintData();
}