void* my_memmove(void* dest, const void* src, size_t n)
{
	char* p1 = (char*)dest;
	const char* p2 = (char*)src;

	if (p2 < p1) {
		p2 += n;
		p1 += n;
		while (n-- != 0)
			*--p1 = *--p2;
	}else{
		while (n-- != 0)
			*p1++ = *p2++;
	}

	return p1;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	char s[]="god like,oh my god";
	char tem[50]="";
	char str[50]="";

	memcpy(tem, s+5, 7);
	cout << tem << endl;

	
	memmove(str, s+5,7);
	cout << str << endl;

	my_memmove(s, s+5, 7);
	cout << s << endl;
	
	getchar();
	return 0;
}