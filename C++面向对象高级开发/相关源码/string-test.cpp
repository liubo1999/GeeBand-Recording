#include "string.h"

int main()
{
	String s1(),
	String s2("hello");

	string s3(s1);
	cout << s3 << endl;
	s3 = s2;

	cout << s3 << endl;
}

void hello
{
	String s1(),
	String s2("hello");

	String* p = new String("hello");
	delete p;
}