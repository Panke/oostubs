# $Id: Makefile,v 1.1.1.1 2002/09/20 20:40:30 gal Exp $

all: bootsect setup

% : %.asm
	nasm -f bin $<

clean:
	rm -f *~ bootsect setup
