#ifndef __MYSTRING__
#define __MYSTRING__


inline
String::String(const char* cstr = 0)
{
	if (cstr) {
		m_data = new char[strlen(cstr)+1];
		strcpy(m_data, cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline
String::~String()
{
	delete[] m_data;
}


inline
String& String::operator = (const String)
{
	if (this == &str)
		return;

	delete[] m_data;
	m_data = new char[ strlen(str.m_data) + 1 ];
	strcpy(m_data, str.m_data);
	return *this;
}

class String
{
public:
	String(const char* cstr = 0);
	String(const String& str);
	String& operator = (const String& str);
	~String();
	char* get_c_str() const { return m_data; }

private:
	char* m_data;
};





#endif