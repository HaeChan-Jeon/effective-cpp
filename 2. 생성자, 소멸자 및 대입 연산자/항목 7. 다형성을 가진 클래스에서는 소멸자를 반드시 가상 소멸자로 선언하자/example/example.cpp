#include <iostream>

class TimeKeeper {
public:
    TimeKeeper();
    virtual ~TimeKeeper();
};
class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch: public TimeKeeper{};

// TimeKeeper에서 파생된 클래스를 통해 동적으로 할당된 객체의 포인터를 반환
TimeKeeper* getTimeKeeper();

class Point {
public:
    Point(int xCoord, int yCoord);
    ~Point();
private:
    int x, y;
};

// 가당찮은 아이디어입니다! std::string은 가상 소멸자가 없단 말입니다.
class SpecialString : public std::string { };

class AWOV {
public:
    virtual ~AWOV() = 0;
};

int main()
{
    // TimeKeeper 클래스 계통으로부터 동적으로 할당된 객체를 얻습니다.
    TimeKeeper *ptk = getTimeKeeper();

    // 자원 누출을 막기 위해 해제(삭제)합니다.
    delete ptk;
}