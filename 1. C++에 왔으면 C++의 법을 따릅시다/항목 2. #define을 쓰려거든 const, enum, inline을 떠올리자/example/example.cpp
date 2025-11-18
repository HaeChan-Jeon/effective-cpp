#include <iostream>

//#define ASPECT_RATIO 1.653

// 대문자로만 표기하는 이름은 대개 매크로에 쓰는 것이어서, 이름 표기로 바꿉니다.
const double AspectRaio = 1.653;

// 포인터는 꼭 const로 선언해 주어야 하고, 이와 아울러 포인터가 가르키는 대상까지 const로 선언
//const char* const authorName = "Scott Meyers";
const std::string authorName("Scott Meyers");

class GamePlayer {
private:
    //enum { NumTurns = 5 };        // "나열자 둔갑술": NumTurns를 5에 대한 기호식 이름으로 만듭니다.
    static const int NumTurns = 5;  // 상수 선언
    int scores[NumTurns];           // 상수를 사용하는 부분

};

// NumTurns의 정의. 값이 주어지지 않는 이유는 아래를 계속 보시면 나옵니다.
const int GamePlayer::NumTurns;



// a와 b 중에 큰 것을 f에 넘겨 호출합니다.
//#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
//
//int a = 5, b = 0;
//CALL_WITH_MAX(++a, b);      // a가 두 번 증가합니다.
//CALL_WITH_MAX(++a, b+10);   // a가 한 번 증가합니다.

template<typename T>                
inline void callWithMax(const T& a, const T& b)
{
    f(a > b ? a : b);
}

int main()
{
}