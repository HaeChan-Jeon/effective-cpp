// operator=을 구현할 때, 어떤 객체가 그 자신에 대입되는 경우를 제대로 처리하도록 만들어야 함
// 원본 객체와 복사대상 객체의 주소를 비교해도 되고, 문장의 순서를 적절히 조절할 수도 있으며,
// 복사 후 맞바꾸기 기법을 써도 됨

// 두 개 이상의 객체에 대해 동작하는 함수가 있다면,
// 이 함수에 넘겨지는 객체들이 사실 같은 객체인 경우에 정확하게 동작하는지 확인해 봐야 함


//class Bitmap {};

//class Widget {
//
//	private:
//		// 힙에 할당된 객체를 가르키는 포인터
//		Bitmap* pb;
//};

// 안전하지 않게 구현된 operator=
//Widget& Widget::operator=(const Widget& rhs)
//{
//	// 객체가 같은지, 즉 자기대입인지 검사하며, 자기대입이면 아무것도 안함
//	if (this == &rhs) return *this;
//
//	// 현재의 비트맵 사용을 중지
//	delete pb;
//	// 이제 rhs의 비트맵을 사용하도록 만듦
//	pb = new Bitmap(*rhs.pb);
//
//	return *this;
//}

//Widget& Widget::operator=(const Widget& rhs)
//{
//	// 원래의 pb를 어딘가에 기억해 둠
//	// 다음, pb가 *pb의 사본을 가르키게 만듦
//	// 원래의 pb를 삭제함
//	Bitmap* pOrig = pb;
//	pb = new Bitmap(*rhs.pb);
//	delete pOrig;
//
//	return *this;
//}

class Widget {
	// *this의 데이터 및 rhs의 데이터를 맞바꿈
	void swap(Widget& rhs);
};

Widget& Widget::operator=(const Widget& rhs)
{
	// rhs의 데이터에 대해 사본을 하나 만듬
	Widget temp(rhs);
	// *this의 데이터를 그 사본의 것과 맞바꿈
	swap(temp);
	return *this;
}