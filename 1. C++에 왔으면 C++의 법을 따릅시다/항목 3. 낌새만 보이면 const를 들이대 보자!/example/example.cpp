#include <iostream>

class CTextBlock {
public:
	std::size_t length() const;

private:
	char* pText;
	// 바로 직전에 계산한 텍스트 길이
	//std::size_t textLength;
	// 이 길이가 현재 유효한가?
	//bool lengthIsValid;

	// 이 데이터 멤버들은 어떤 순간에도 수정이 가능합니다.
	// 심지어 상수 멤버 함수 안에서도  수정할 수 있습니다.
	mutable std::size_t textLength;
	mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const
{
	if (!lengthIsValid) {
		// 에러! 상수 멤버 함수 안에서는 textLength 및 lengthIsValid에 대입할 수 없습니다.
		//textLength = std::strlen(pText);
		//lengthIsValid = true;

		// 이제 문제 없습니다.
		textLength = std::strlen(pText);
		lengthIsValid = true;
	}

	return textLength;
}

int main()
{
}