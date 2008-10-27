#!/bin/sh -

CONFDIR="-q -f /USRDIR/.bochsrc"
if [ $# -eq 1 ]
then
	IMAGE="floppya:1_44=$1,status=inserted"
fi

bochs $CONFDIR $IMAGE
