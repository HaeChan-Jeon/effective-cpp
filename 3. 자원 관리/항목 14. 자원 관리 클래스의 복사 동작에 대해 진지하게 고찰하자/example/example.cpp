// RAII 객체의 복사는 그 객체가 관리하는 자원의 복사 문제를 안고 가기 때문에,
// 그 자원을 어떻게 복사하느냐에 따라 RAII 객체의 복사 동작이 결정됨
// RAII 클래스에 구현하는 일반적인 복사 동작은 복사를 금지하거나 참조 카운팅을 해 주는 선으로 마무리하는 것임
// 하지만 이 외의 방법들도 가능하니 참고해 두면 좋음

#include <mutex>;

using namespace std;

class Lock {
public:
    explicit Lock(std::mutex& m) : mutexRef(m)
    { mutexRef.lock(); }

    ~Lock() { mutexRef.unlock(); }

    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;

private:
    std::mutex& mutexRef;
};

// 사용하고 싶은 뮤텍스를 정의
mutex m;

int main()
{
	{
		// 임계 영역을 저장하기 위해 블록을 만들고, 뮤텍스에 잠금을 검
		Lock ml(m);
		// 임계 영역에서 할 연산을 수행
	}
}