#include <iostream>

template<typename T>
class NamedObject {
public:
    // 이 생성자는 이제 상수 타입의 name을 취하지 않습니다.
    // nameValue가 비상수 string의 참조자가 되었기 때문입니다.
    // 참조할 string을 가져야 하기 때문에 char*는 없애 버렸습니다.
    NamedObject(const std::string& name, const T& value);
private:
    std::string& nameValue;
    const T objectValue;
};

int main()
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    p = s;
}