extern void (*__CTOR_LIST__[])();
extern void (*__CTOR_LIST_END__[])();
extern void (*__DTOR_LIST__[])();
extern void (*__DTOR_LIST_END__[])();

/* Bei Cygnus gnu-win32 und aelteren DJGPP Versionen wird in main () ein
   Aufruf von __main () generiert, der die Ausfuehrung der gloalen
   Konstruktoren erledigen soll.                                           */

void __main () {}

/* _init und _fini werden aus 'startup.asm' heraus aufgerufen              */

void init () {
  int ctor;

  for (ctor = 0; ctor < __CTOR_LIST_END__ - __CTOR_LIST__; ctor++)
    (*(__CTOR_LIST__[ctor]))();
}

void fini () {
  int dtor;

  for (dtor = 0; dtor < __DTOR_LIST_END__ - __DTOR_LIST__; dtor++)
    (*(__DTOR_LIST__[dtor]))();
}

