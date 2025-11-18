#include <iostream>
#include <vector>

//void f1(const Widget* pw);		// f1은 상수 widget 객체에 대한
//									// 포인터를 매개변수로 취합니다.
//
//void f2(Widget const* pw);		// f2도 그렇고요.

int main()
{
	char greeting[] = "Hello";

	char* p = greeting;				// 비상수 포인터,
									// 비상수 데이터

	const char* p = greeting;		// 비상수 포인터,
									// 상수 데이터

	char* const p = greeting;		// 상수 포인터
									// 비상수 데이터

	const char* const p = greeting;	// 상수 포인터,
									// 상수 데이터



	std::vector<int> vec;

	const std::vector<int>::iterator iter = vec.begin();
									// iter는 T* const처럼 동작합니다.
	*iter = 10;						// OK, iter가 가르키는 대상을 변경합니다.
	//++iter;						// 에러! iter는 상수입니다.

	std::vector<int>::const_iterator cIter = vec.begin();
									// cIter는 const T*처럼 동작합니다.
	//*cIter = 10;					// 에러! *cIter가 상수이기 때문에 안됩니다.
	++cIter;						// 이건 문제없습니다. cIter를 변경하니까요.



	class Rational {};
	const Rational operator*(const Rational& lhs, const Rational& rhs);

	Rational a, b, c;
	//(a* b) = c;					// a*b의 결과에 대고
									// operator=를 호출하다니요!

	//if (a * b = c)				// 어흑, 나는 원래 비교하려고 그랬던 건데!
}