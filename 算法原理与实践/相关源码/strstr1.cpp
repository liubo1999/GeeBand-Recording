
#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int mystrstr(string src, string tar)
{
	if (src.length() == 0 || tar.length() == 0) {
		return -1;
	}

	int i, j;
	for (i = 0; i < src.length() - tar.length() + 1; i++) {
		for (j = 0; j < tar.length(); j++) {
			if (src[i + j] != tar[j]) {
				break;
			}
		}
	
		if (j == tar.length()) {
			return i;
		}
	}

	return -1;
}


int _tmain(int argc, _TCHAR* argv[])
{	
	string source = "fdsadfads";
	string search = "sa";
	int p = mystrstr(source, search);
	if (p > 0)
		cout << "find in " << p << endl;
	else
		cout << "NotFound" << endl;

	return 0;
}

