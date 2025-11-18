#include <iostream>
#include <list>

class PhoneNumber { };

class ABEntry {
public:
	ABEntry(const std::string& name, const std::string& address,
		const std::list<PhoneNumber>& phones);

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

//ABEntry::ABEntry(const std::string & name, const std::string & address,
//	const std::list<PhoneNumber>& phones)
//{
//	// 지금은 모두 대입을 하고 있습니다. 초기화가 아닙니다.
//	theName = name;
//	theAddress = address;
//	thePhones = phones;
//	numTimesConsulted = 0;
//}

ABEntry::ABEntry(const std::string& name, const std::string& address,
					const std::list<PhoneNumber>& phones)
// 이제 이들은 모두 초기화되고 있습니다.
// 생성자 본문에 이제 아무것도 들어가 있지 않고요.
: theName(name),
theAddress(address),
thePhones(phones),
numTimesConsulted(0)
{ }

//ABEntry::ABEntry(const std::string& name, const std::string& address,
//	const std::list<PhoneNumber>& phones)
//	: theName(),
//	theAddress(),
//	thePhones(),
//	numTimesConsulted(0)
//{
//}

//// 여러분의 라이브러리에 포함된 클래스
//class FileSystem {
//public:
//	// 많고 많은 멤버 함수들 중 하나
//	std::size_t numDists() const;
//};
//
//// 사용자가 쓰게 될 객체
//extern FileSystem tfs;
//
//// 라이브러리의 사용자가 만든 클래스
//class Directory {
//public:
//	Directory();
//};
//Directory::Directory()
//{
//	// tfs 객체를 여기서 사용함
//	std::size_t disks = tfs.numDists();
//}

// 이전과 다를 것 없는 클래스
class FileSystem {
public:
	std::size_t numDists() const;
};

// tfs 객체를 이 함수로 대신합니다. 이 함수는 클래스 안에 정적 멤버로 들어가도 됩니다.
// 지역 정적 객체를 정의하고 초기화합니다. 이 객체에 대한 참조자를 반환합니다.
FileSystem& tfs()
{
	static FileSystem fs;
	return fs;
}

// 역시 이전과 다를 것 없는 클래스
class Directory {
public:
	Directory();
};

// 이전과 동일합니다. tfs의 참조자였던 것이 지금은 tfs()로 바뀌었다는 것만 다릅니다.
Directory::Directory()
{
	// tfs 객체를 여기서 사용함
	std::size_t disks = tfs().numDists();
}

// tempDir 객체를 이 함수로 대신합니다. 이 함수는 Directory 클래스의 정적 멤버로 들어가도 됩니다.
// 지역 정적 객체를 정의/초기화합니다. 이 객체에 대한 참조자를 반환합니다.
Directory& tempDir()
{
	static Directory td;
	return td;
}

int main()
{
	// int의 직접 초기화
	int x = 0;

	// 포인터의 직접 초기화
	const char* text = "A C-style string";

	// 입력 스트링에서 읽음으로써 "초기화" 수행
	double d;
	std::cin >> d;

	// 임시 파일을 담는 디렉토리
	Directory& tDir = tempDir();
}