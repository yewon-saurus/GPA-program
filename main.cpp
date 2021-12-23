/***********************************************************************/
/*
		HW#12: 성적처리프로그램#4 - 다형성과 가상함수

작성자: 김예원									  날짜: 2021년  6월  10일

문제 정의:
	- #12-1. 다형성을 지원하도록 IOInterface Class 수정
	  IOInterface Class를 상속받는 Subject 및 Student Class 작성 후 테스트
	- #12-2. 추상 클래스 작성: IOInterface Class를 추상 클래스로 변경
	  멤버변수 삭제
	  멤버함수 InputData(), PrintData(),Modify()를 모두 순수가상함수로 변경
	- #13-3. 학생들의 성적을 처리하고 관리하는 GradeManager 클래스 작성

교과목 별 평점 계산
A+     A     B+     B     C+     C     D+     D     F
4.5    4.0   3.5    3.0   2.5    2.0   1.5    1.0   0.0

*/
/***********************************************************************/
#include "Student.h"
#include "GradeManager.h"
using namespace std;

int main() {
	// #12-1. 다형성 지원, #12-2. 추상클래스
	Student std;
	std.InputData();

	IOInterface* IO[2] = {new Subject("사진학", 3, "A+"), &std};
	for (int i = 0; i < 2; i++) {
		cout << "\n * " << i + 1 << "번째 데이터 : " << "\n";
		IO[i]->PrintData(); // 파생클래스의 멤버함수가 호출되어야 함
	}

	/*
	#12-1. 다형성 지원
	코드를 실행시켰을 때 파생 클래스의 멤버함수가 호출되도록
	IOInterface Class를 수정하시오. 왜 그렇게 수정하였는지 근거를 대시오.

		:
		기본 클래스의 포인터로 호출하더라도 파생 클래스에서 재정의된 함수를 호출하려면,
		기본 클래스의 멤버 함수를 가상 함수로 선언해야 한다.
		따라서 IOInterface Class의 모든 멤버 함수에 virtual 키워드를 붙여주었다.
	*/

	// #12-3. GradeManager Class 작성
	int stdnum;
	cout << "입력할 학생 수를 입력 : ";
	InputUtil::InputValue(stdnum);
	cout << endl;
	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();
}