#include "complex.h"


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