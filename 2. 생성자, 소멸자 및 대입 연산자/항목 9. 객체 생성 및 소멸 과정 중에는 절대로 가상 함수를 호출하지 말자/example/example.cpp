// 모든 거래에 대한 기본 클래스
class Transaction {
public:
	Transaction();
	// 타입에 따라 달라지는 로그 기록을 만듭니다.
	virtual void logTransaction() const = 0;
};

// 기본 클래스 생성자의 구현
Transaction::Transaction()
{
	// 마지막 동작으로, 이 거래를 로깅(하기 시작)합니다.
	logTransaction();
}

// Transaction의 파생 클래스
class BuyTransaction : public Transaction {
public:
	// 이 타입에 따른 거래내역 로깅을 구현합니다.
	virtual void logTransaction() const;
};

// 역시 파생 클래스
class sellTransaction : public Transaction {
public:
	// 이 타입에 따른 거래내역 로깅을 구현합니다.
	virtual void logTransaction() const;
};


int main()
{
	BuyTransaction b;
}