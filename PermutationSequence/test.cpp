#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str = "12345";
	auto a = next(str.begin(), 2);
	str.erase(a);
	cout << str << endl;
}