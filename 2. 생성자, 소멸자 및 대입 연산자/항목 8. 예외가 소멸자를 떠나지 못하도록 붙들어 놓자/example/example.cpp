#include <vector>

class Widget {
public:
    ~Widget() {}
};
void doSomething()
{
    std::vector<Widget> v;
}

class DBConnection {
public:
    // DBConnection 객체를 반환하는 함수. 매개변수는 편의상 생략
    static DBConnection create();
    // 연결을 닫습니다. 이때 연결이 실패하면 예외를 던짐
    void close();
};

// DBConnection 객체를 관리하는 클래스
//class DBConn {
//public:
//    DBConn(DBConnection dbFile) : db(dbFile) { }
//
//    // 데이터베이스 연결이 항상 닫히도록 확실히 챙겨주는 함수
//    ~DBConn()
//    {
//        db.close();
//    }
//private:
//    DBConnection db;
//};

// close에서 예외가 발생하면 프로그램을 바로 끝냅니다. 대개 abort를 호출합니다.
DBConn::~DBConn()
{
    try { db.close(); }
    catch (...) {
        // close 호출이 실패했다는 로그를 작성합니다;
        std::abort();
    }
}

// close를 호출한 곳에서 일어난 예외를 삼켜버립니다.
DBConn::~DBConn()
{
    try { db.close(); }
    catch (...) {
        // close 호출이 실패했다는 로그를 작성합니다;
    }
}

// 더 좋은 전략
class DBConn {
public:
    DBConn(DBConnection dbFile) : db(dbFile) {}

    // 사용자 호출을 배려해서 새로 만든 함수
    void close()
    {
        db.close();
        closed = true;
    }

    // 사용자가 연결을 안 닫았으면 여기서 닫아봅니다.
    // 연결을 닫다가 실패하면, 실패를 알린 후에 실행을 끝내거나 예외를 삼킵니다.
    ~DBConn()
    {
        if (!closed)
        try {
            db.close();
        }
        catch (...) {
            // close 호출이 실패했다는 로그를 작성합니다;
        }
    }
private:
    DBConnection db;
    bool closed;
};

int main()
{
    DBConn dbc(DBConnection::create());
}