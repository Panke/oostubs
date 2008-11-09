/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/


#include "object/o_stream.h"
#include <cstdlib>
#include <cstddef>

using std::size_t;

O_Stream::O_Stream(Base b) : Stringbuffer(), base(b)
{};

O_Stream& O_Stream::operator<<(char c)
{
	this->put(c);
	return *this;
}

int ulong_to_char_stack(unsigned long n, char* stack, int base)
{
	char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int i = 69; 
	do
	{
		int reminder = n%base;
		n /= base;
		stack[i] = (digits[reminder]); 
		--i;
	} while(n > 0);
	if(base == 16) {
		stack[i] = 'x';
		--i;
	}
	if(base == 8 or base == 16) {
		stack[i] = '0';
		--i;
	}
	if(base == 2) {
		stack[i] = 'b';
		--i;
	}
	return i;
}


O_Stream& O_Stream::operator<<(long n) 
{

	char stack_[70];
	int i = ulong_to_char_stack((unsigned long) n, stack_, this->base);

	if(n < 0)
	{
		// push the sign an the stack and threat it as an positive number
		stack_[i]='-';
		--i;
	}

	for(int j = i+1; j < 70; ++j)
	{
		this->put(stack_[j]);
	}

	return *this;
}

O_Stream& O_Stream::operator<<(unsigned long n)
{
	char stack_[70];
	int i = ulong_to_char_stack(n, stack_, this->base);

	for(int j = i+1; j < 70; ++j)
	{
		this->put(stack_[j]);
	}
	return *this;
}

O_Stream& O_Stream::operator<<(short n) 
{
	return operator<<((long)n);
}
O_Stream& O_Stream::operator<<(unsigned short n) 
{
	return operator<<((unsigned long)n);
}
O_Stream& O_Stream::operator<<(int n) 
{
	return operator<<((long)n);
}

O_Stream& O_Stream::operator<<(unsigned int n) 
{
	return operator<<((unsigned long)n);
}

O_Stream& O_Stream::operator<<(unsigned char n) 
{
	return operator<<((unsigned long)n);
}

O_Stream& O_Stream::operator<<(void* pointer)
{
	Base tmp = this->base;
	this->base = HEX;
	operator<<((unsigned long)pointer);
	this->base = tmp;
	return *this; 
}

O_Stream& O_Stream::operator<<(const char* text)
{
	while(*text != '\0')
	{
		this->put(*text);
		text++;
	}
	return *this;
}

O_Stream& O_Stream::operator<<(O_Stream& (*func) (O_Stream&))
{
	return func(*this);
}

O_Stream& endl(O_Stream& stream)
{
	stream.put('\n');
	stream.flush();
	return stream;
}

O_Stream& bin(O_Stream& stream)
{
	stream.base = O_Stream::BIN;
	return stream;
}

O_Stream& hex(O_Stream& stream)
{
	stream.base = O_Stream::HEX;
	return stream;
}

O_Stream& dec(O_Stream& stream)
{
	stream.base = O_Stream::DEC;
	return stream;
}

O_Stream& oct(O_Stream& stream)
{
	stream.base = O_Stream::OCT;
	return stream;
}



