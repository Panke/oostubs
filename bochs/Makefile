# -----------------------------------------------------------------------------
#
#                              M A K E F I L E
#
# zum Uebungsbetriebssystem OO-Stubs der Lehrveranstaltung
# 'Betriebssysteme I'.
# -----------------------------------------------------------------------------
#
# Durch Eingabe von 'make' werden die Pfadangaben des bochs angepasst.
# Dazu wird der Platzhalter '/USRDIR' mit dem aktuellem Systempfad ersetzt.
#
# -----------------------------------------------------------------------------

USRDIR=$(shell pwd)

all:
	@sed -ie "s^/USRDIR^$(USRDIR)^" ./bochs.sh
	@sed -ie "s^/USRDIR^$(USRDIR)^" ./.bochsrc
	@rm ./bochs.she
	@rm ./.bochsrce
