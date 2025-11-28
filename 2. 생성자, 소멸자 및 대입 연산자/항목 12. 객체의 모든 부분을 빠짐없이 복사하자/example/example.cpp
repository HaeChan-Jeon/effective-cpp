// 객체 복사 함수는 주어진 객체의 모든 데이터 멤버 및 모든 기본 클래스 부분을 빠뜨리지 말고 복사해야 함
// 클래스의 복사 함수 두 개를 구현할 때, 한쪽을 이용해서 다른 쪽을 구현하려는 시도는 절대로 하면 안 됨
// 그 대신, 공통된 동작을 제3의 함수에다 분리해 놓고 양쪽에서 이것을 호출하게 만들어서 해결해야 함

#include <string>

void logCall(const std::string& funcName);

class Date {};

class Customer {
	public:
		Customer(const Customer& rhs);
		Customer& operator=(const Customer& rhs);

	private:
		std::string name;
		Date lastTransaction;
};

Customer::Customer(const Customer& rhs)
	: name(rhs.name)
{
	logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	name = rhs.name;
	return *this;
}

class PriorityCustomer : public Customer {
	public:
		PriorityCustomer(const PriorityCustomer& rhs);
		PriorityCustomer& operator=(const PriorityCustomer& rhs);

	private:
		int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
	: Customer(rhs),
	priority(rhs.priority)
{
	logCall("Prioritycustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
	logCall("Priority copy assignment operator");

	// 기본 클래스 부분을 대입함
	Customer::operator=(rhs);
	priority = rhs.priority;
	return *this;
}

int main()
{
}