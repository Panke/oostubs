/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/o_stream.h"
#include <stack>
#include <cstdlib>


O_Stream::O_Stream(Base b) : Stringbuffer(1024), base(b)
{};

O_Stream::O_Stream(Base b, size_t size)
	: Stringbuffer(size), base(b) {}

O_Stream& O_Stream::operator<<(char c)
{
	this->put(c);
	return *this;
}

O_Stream& O_Stream::operator<<(long n) 
{
	std::stack<char> stack_;
	//TODO: convert the values to chars and represent the sign
	if(n < 0)
	{
		// push the sign an the stack and threat it as an positive number
		stack_.push('-');
		n *= -1;
	}
	if(this->base == OCT or this->base == HEX)
		stack_.push('0');
	if(this->base == HEX)
		stack_.push('x');

	do
	{
		long rem = n%this->base;
		n /= this->base;
		// in ASCII Number start at 30, we should consider to make this
		// more generic
		stack_.push((char)(rem+30)); 
	} while(n > 0);

	while(!stack_.empty())
	{
		this->put(stack_.top());
		stack_.pop();
	}
	return *this;
}

O_Stream& O_Stream::operator<<(unsigned long n)
{
	std::stack<char> stack_;

	if(this->base == OCT or this->base == HEX)
		stack_.push('0');
	if(this->base == HEX)
		stack_.push('x');

	do 
	{
		long rem = n%this->base;
		n = n % this->base;
		stack_.push((char)(rem+30));
	} while(n > 0);

	while(!stack_.empty()) 
	{
		this->put(stack_.top());
		stack_.pop();
	}
	return *this;
}

