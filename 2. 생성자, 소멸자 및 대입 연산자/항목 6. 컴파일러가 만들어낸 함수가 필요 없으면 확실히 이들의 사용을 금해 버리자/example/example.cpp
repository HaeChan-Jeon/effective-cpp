#include <iostream>

//class HomeForSale {
//public:
//private:
//    HomeForSale(const HomeForSale&);
//    HomeForSale& operator=(const HomeForSale&);
//};

class HomeForSale : private Uncopyable {
};

class Uncopyable {
protected:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

int main()
{
    std::cout << "Hello World!\n";
}