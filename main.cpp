/***********************************************************************/
/*
		HW#10: 성적처리프로그램#4 - 상속

작성자: 김예원									  날짜: 2021년  5월  30일

문제 정의:
	- IOInterface Class 작성
	- 파생클래스 작성
		- Subject Class
		- Student Class
	- Student Class의 Modify() 함수 변경

교과목 별 평점 계산
A+     A     B+     B     C+     C     D+     D     F
4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0

*/
/***********************************************************************/
#include "Student.h"
using namespace std;

int main() {
	// 11 - 2.
	//Student stu;
	//cout << stu.GetData() << "\n"; // IOInterface Class에서 상속받은 멤버함수 호출


	// 11 - 3.
	Subject sub("컴퓨터", 3, "C");
	cout << "-----------------------------\n";

	cout << "m_data : " << sub.IOInterface::GetData() << endl;
	cout << "교과목의 이름: " << sub.Subject::GetName() << endl;
	cout << "부모클래스의 이름: " << sub.IOInterface::GetName() << endl;

	cout << "-----------------------------\n\n";

	Student std("홍길동", 2013909845, 1, &sub);

	cout << "-----------------------------\n";

	cout << "m_data: " << std.IOInterface::GetData() << endl;
	cout << "학생의 이름: " << std.Student::GetName() << endl;
	cout << "부모클래스의 이름: " << std.IOInterface::GetName() << endl;

	cout << "-----------------------------\n\n";


	// 11 - 4.
	//Subject sub("컴퓨터", 3, "C");
	//Student std("홍길동", 20138342, 1, &sub);

	//std.PrintData();
	//std.Modify(); // Student Class의 멤버변수 값 수정
	//std.PrintData();
}