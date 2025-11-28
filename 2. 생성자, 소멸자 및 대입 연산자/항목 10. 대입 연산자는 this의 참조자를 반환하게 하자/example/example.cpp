// 대인 연산자는 *this의 참조자를 반환하도록 만드세요.

class Widget {
public:
	// 반환 타입은 현재의 클래스에 대한 참조자
	Widget& operator=(const Widget& rhs)
	{
		// 좌변 객체(의 참조자)를 반환
		return *this;
	}

	// +=, -=, *= 등에도 동일한 규약이 적용
	Widget& operator+=(const Widget& rhs)
	{
		return *this;
	}

	// 대입 연산자의 매개변수 타입이 일반적이지 않은 경우에도 동일한 규약을 적용
	Widget& operator+=(int rhs)
	{
		return *this;
	}
};