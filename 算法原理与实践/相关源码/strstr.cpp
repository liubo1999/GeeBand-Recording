// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

char *mystrstr(const char* s1, const char* s2)
{
	const char* p = s1;
	const size_t len = strlen(s2);
	
	for (; (p = strchr(p, *s2)) != 0; p++)
	{
		if (strncmp(p, s2, len) == 0)
			return (char*)p;
	}

	return (0);
}


int _tmain(int argc, _TCHAR* argv[])
{	
	char* source = "nfiadfade";
	char* search = "fa";
	char*p = mystrstr(source, search);
	if (p)
		cout << "OK" << endl;
	else
		cout << "NotFound" << endl;



	return 0;
}



