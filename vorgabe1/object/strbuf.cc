/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"
#include <cstddef>

using std::size_t;


Stringbuffer::Stringbuffer()
{
	this->end = buffer;
}

Stringbuffer::~Stringbuffer()
{
}

void Stringbuffer::put(char c)
{
	if(end >= buffer+size)
		this->flush();
	else {
		*end = c;
		++end;
	}
}

