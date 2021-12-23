#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include <iostream>
#include <string>

/*
	InputValue 함수
	다른 자료형도 입력할 수 있도록 확장
*/
using namespace std;
class InputUtil {
public:
	inline static void InputValue(int& i);
	inline static void InputValue(string& str);
	inline static void InputValue(char* c_str);
	inline static void InputValue(float& f);
	inline static void InputValue(double& d);
};
#endif

inline void InputUtil::InputValue(int& i) {
	cin >> i;
	cin.ignore();
}
inline void InputUtil::InputValue(string& str) {
	getline(cin, str);
}
inline void InputUtil::InputValue(char* c_str) {
	cin >> c_str;
}
inline void InputUtil::InputValue(float& f) {
	cin >> f;
	cin.ignore();
}
inline void InputUtil::InputValue(double& d) {
	cin >> d;
	cin.ignore();
}