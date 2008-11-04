/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/
/*

#include "object/strbuf.h"
#include <cstddef>

using std::size_t;


Stringbuffer::Stringbuffer(size_t size)
{
	this->buffer = new char[size];
	this->end = buffer;
	this->size = size;
}

Stringbuffer::~Stringbuffer()
{
	delete[] buffer;
}

void Stringbuffer::put(char c)
{
	if(end >= buffer+this->size)
		this->flush();
	else {
		*end = c;
		++end;
	}
}
*/
