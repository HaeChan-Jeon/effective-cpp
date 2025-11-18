#include <iostream>

class TextBlock {
public:
	const char& operator[] (std::size_t position) const
	{
		return text[position];
	}

	// 상수 버전 op[]를 호출하고 끝
	char& operator[] (std::size_t position)
	{
		return
			const_cast<char&>(					// op[]의 반환 타입에 캐스팅을 적용
												// const를 떼어냅니다.
				static_cast<const TextBlock&>	// *this의 타입에 const를 붙입니다.
					(*this)[position]			// op[]의 상수 버전을 호출합니다.
			);
	}

private:
	char* text;
};

int main()
{
}