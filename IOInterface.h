#ifndef IOINTERFACE_H
#define IOINTERFACE_H
#include <iostream>
#include <string>
#include "InputUtil.h"

using namespace std;
class IOInterface {
public:
	virtual ~IOInterface() {			// 소멸자
		cout << "IOInterface 소멸자 호출!" << endl;
	}
	virtual void InputData() = 0;			// 멤버변수의 값 입력
	virtual void PrintData() const = 0;		// 멤버변수의 값 출력
	virtual void Modify() = 0;				// 멤버변수의 값 수정
};
#endif