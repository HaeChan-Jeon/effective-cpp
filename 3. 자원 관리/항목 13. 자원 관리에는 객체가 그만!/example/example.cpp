// 자원 누출을 막기 위해, 생성자 안에서 자원을 힉득하고 소멸자에서 그것을 해제하는 RAII 객체를 사용

#include <memory>

// 여러 형태의 투자를 모델링한 클래스 계통의 최상위 클래스
class Investment {};

// Investment 클래스 계통에 속한 클래스의 객체를 동적 할당하고 그 포인터를 반환함
// 이 객체의 해제는 호출자 쪽에서 직접해야 함 (매개변수는 복잡하니깐 제외)
Investment* createInvestment();

void f()
{
	// 팩토리 함수를 호출합니다.
	auto pInv = std::make_unique<Investment>(createInvestment());
	// 예전처럼 pInv를 사용합니다.

	auto spInv = std::shared_ptr<Investment>(createInvestment());
}

int main()
{
}
