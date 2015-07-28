#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream.h>

complex&
__doapl (complex* ths, const complex& r)
{
	ths-> += r.re;
	ths-> += r.im;
	return *ths;
}


inline complex&
complex::operator += (const complex& r)
{
	return __doapl (this, r);
}


//必须放在新的函数里，所以绝不能使用&
inline complex
operator + (const complex& x, const complex& y)
{
	//返回临时对象
	return complex ( real (x) + real (y),
					 imag (x) + imag (y) );

}


inline complex
operator + (const complex& x, double y)
{
	//返回临时对象
	return complex ( real (x) + y, imag (x) );

}


inline complex
operator + (double x, const complex& y)
{
	//返回临时对象
	return complex ( x + real (y), imag (y) );

}

ostream&
operator << (ostream& os,
			 const complex& x)
{

}


class complex
{
public:
	complex (double r = 0; double i = 0)
		: re (r), im (i)
	{ }
	complex& operator += (const complex&);
	double real ()     { return re; }
	double imag ()     { return im; }

private:
	double re, im;

	friend complex& __doapl (complex*,
							 const complex&);

};




#endif

