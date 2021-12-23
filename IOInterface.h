#ifndef IOINTERFACE_H
#define IOINTERFACE_H
#include <iostream>
#include <string>
#include "InputUtil.h"

using namespace std;
class IOInterface {
protected:
	string m_name;
	int m_data;

public:
	IOInterface() {
		this->m_name = "";
		this->m_data = 0;
		cout << "IOInterface 디폴트 생성자 호출!" << endl;
	}
	IOInterface(string m_name) { // 인자있는 생성자
		this->m_name = m_name;
		cout << "IOInterface 인자있는 생성자 호출!" << endl;
	}
	~IOInterface() {			// 소멸자
		cout << "IOInterface 소멸자 호출!" << endl;
	}
	void InputData() {			// 멤버변수의 값 입력
		cout << "name: ";
		InputUtil::InputValue(m_name);
		cout << "data: ";
		InputUtil::InputValue(m_data);
	}
	void PrintData() const {	// 멤버변수의 값 출력
		cout << m_name << endl;
		cout << m_data << endl;
	}
	void Modify() {				// 멤버변수의 값 수정
		if (this != NULL) {
			cout << "name: ";
			InputUtil::InputValue(this->m_name);
			cout << "data: ";
			InputUtil::InputValue(this->m_data);
		}
		else {
			cout << "해당 data가 없습니다.\n\n";
		}
	}
	string GetName() const {	// 접근자 함수
		return m_name;
	}
	int GetData() const {		// 접근자 함수
		return m_data;
	}
};
#endif