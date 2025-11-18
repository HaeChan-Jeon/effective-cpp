#include <iostream>

class CTextBlock {
public:
	// 부적절한 (그러나 비트수준 상수성이 있어서 허용되는) operator[]의 선언
	char& operator[] (std::size_t position) const	
	{ return pText[position]; }

private:
	char* pText;
};

int main()
{
	// 상수 객체를 선언합니다.
	const CTextBlock cctb("Hello");

	// 상수 버전의 operator[]를 호출하여 cctb의 내부 데이터에 대한 포인터를 얻습니다.
	char* pc = &cctb[0];

	// cctb는 이제 "Jello라는 값을 갖습니다.
	*pc = 'J';
}