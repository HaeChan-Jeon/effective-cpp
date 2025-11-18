#include <iostream>

class TextBlock {
public:
	TextBlock(std::string s) : text(s) {}

	const char& operator[] (std::size_t position) const	// 상수 객체에 대한
	{ return text[position]; }							// operator[]

	char& operator[] (std::size_t position)				// 비상수 객체에 대한
	{ return text[position]; }							// operator[]

private:
	std::string text;
};

void print(const TextBlock& ctb)	// 이 함수에서 ctb는 상수 객체로 쓰입니다.
{
	std::cout << ctb[0];			// TextBlock::operator[]의 상수
									// 멤버를 호출합니다.
}

int main()
{
	TextBlock tb("Hello");			// TextBlock::operator[]의
	std::cout << tb[0];				// 비상수 멤버를 호출합니다.

	const TextBlock ctb("World");	// TextBlock::operator[]의
	std::cout << ctb[0];			// 상수 멤버를 호출합니다.

	std::cout << tb[0];				// 좋습니다. 비상수 버전의
									// TextBlock 객체를 읽습니다.

	tb[0] = 'x';					// 역시 문제없죠. 비상수 버전의
									// TextBlock 객체를 읽습니다.

	std::cout << ctb[0];			// 좋습니다. 상수 버전의
									// TextBlock 객체를 읽습니다.

	//ctb[0] = 'x';					// 컴파일 에러 발생! 상수 버전의
									// TextBlock 객체를 대해 쓰기는 안 됩니다.
}