# -----------------------------------------------------------------------------
# 
#                              M A K E F I L E
# 
# zum Uebungsbetriebssystem OO-Stubs der Lehrveranstaltung 
# 'Betriebssysteme I'.
# -----------------------------------------------------------------------------
# Einstellungen in Abhaengigkeit vom Generierungssystem:
#
#    GENSYS:       Generierungssystem: Wahlweise 'Linux', 'Win98' oder 'WinNT'
#                  `WinNT` f�r Windows NT, 2000, XP
#    ASMOBJFORMAT: Ausgabeformat fuer den Assembler. Das Format muss dem
#                  jeweiligen Format des verwendeten C++ Compilers angepasst
#                  werde, damit gemischte Objektdateien gelinkt werden koennen.
#    OBJDIR:       Verzeichnis, in dem die Objektdateien abgelegt werden
#                  sollen.
#    DRIVE:        Laufwerk, auf das das System-Image geschrieben wird.
#    DELETE:       Name des Kommandos zum Loeschen von Dateien
#    ASM:          Zu benutzender Assembler
#    CC/CXX:       Zu benutzender C/C++-Compiler.
#    CFLAGS:       Flags fuer den Compileraufruf.
#    LD:           Zu benutzender Linker.
#    LDFLAGS:      Flags fuer den Linkeraufruf
#    LDLIBS:       Dazuzulinkende Bibliotheken
#    LDHEAD:       Am Anfang zu linkende Dateien
#    LDTAIL:       Am Ende zu linkende Dateien
GENSYS       = Linux
ASMOBJFORMAT = elf
OBJDIR       = ./build
ASM    = nasm
CC     = gcc
CXX    = g++
DELETE = rm
LD     = ld
OBJCP  = objcopy
TCC    = gcc

ifeq ($(GENSYS),Linux)
ifneq ($(shell uname),$(GENSYS))
CC     = i386-elf-gcc
CXX    = i386-elf-g++
LD     = i386-elf-ld
MAKE   = gmake
OBJCP  = i386-elf-objcopy
endif
DRIVE  = /dev/fd0
LDHEAD = $(shell $(CXX) --print-file-name=crti.o && $(CXX) --print-file-name=crtbegin.o)
LDTAIL = $(shell $(CXX) --print-file-name=crtend.o && $(CXX) --print-file-name=crtn.o)
else
DRIVE  = a:
LDHEAD = $(shell $(CXX) --print-file-name=crtbegin.o)
LDTAIL = $(shell $(CXX) --print-file-name=crtend.o)
C_SOURCES += ../inifini/inifini.c
endif

BOOT   = ../boot
TOOLS  = ../tools
BOOTDEVICE = 0:80:2:18:0:0:1
USRDIR = $(shell pwd | cut -c-4444)

# Liste der Quelltexte:
ASM_SOURCES = $(shell find . -name "*.asm")
C_SOURCES   += $(shell find . -name "*.c")
CC_SOURCES  += $(shell find . -name "*.cc")
# -------------------------------------------------------------------------

# Namen der Unterverzeichnisse mit den Quelltexten
# (wird automatisch aus den Quelltextdateien ermittelt und vom Compiler
# benutzt, um die Quelltexte zu finden.)
VPATH = $(sort $(dir $(CC_SOURCES) $(C_SOURCES) $(ASM_SOURCES)))

# Listen mit den Objektdateien, die beim Kompilieren entstehen:
# (werden automatisch aus den Quelltextdateinamen ermittelt)
ASM_OBJECTS  = $(patsubst %.asm,_%.o, $(notdir $(ASM_SOURCES)))
C_OBJECTS    = $(notdir $(C_SOURCES:.c=.o))
CC_OBJECTS   = $(notdir $(CC_SOURCES:.cc=.o))

STARTUP_OBJ  = $(OBJDIR)/_startup.o

OBJPRE = $(addprefix $(OBJDIR)/,$(filter-out _startup.o, $(ASM_OBJECTS)) $(C_OBJECTS) $(CC_OBJECTS))
# --------------------------------------------------------------------------

# Regeln zur Erzeugung der Objektdateien
CFLAGS   := $(CFLAGS) -fleading-underscore -Wall -I. -fno-exceptions -m32
CXXFLAGS := $(CXXFLAGS) -fleading-underscore -Wall -I. -fno-rtti -fno-exceptions -m32

$(OBJDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o : %.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJDIR)/_%.o : %.asm
	$(ASM) -f $(ASMOBJFORMAT) -o $@ $<

# -------------------------------------------------
# Default target
all: $(OBJDIR)/bootdisk.vmi

# -------------------------------------------------
# Linken des Systems
$(OBJDIR)/system: $(OBJDIR) $(STARTUP_OBJ) $(OBJPRE)
	$(LD) -e startup -T sections -o $(OBJDIR)/system $(LDFLAGS) $(STARTUP_OBJ) $(LDHEAD) $(OBJPRE) $(LDTAIL) $(LDLIBS)

# -------------------------------------------------
# Regel zur Erzeugung des Objektdateiverzeichnisses
$(OBJDIR) :
	mkdir $(OBJDIR)

# -------------------------------------------------------------------------
# Ab hier folgt die Definition der targets,
.PHONY: clean depend

# 'system.img' enthaelt die zu ladenden Sections des eigentlichen Systems
$(OBJDIR)/system.img : $(OBJDIR)/system
	$(OBJCP) -O binary $< $@

# 'bootdisk.img' besteht aus dem 'system.img', das um den (parametrisierten)
# Bootblock und den Setup-Code erweitert wurde.
$(OBJDIR)/bootdisk.img : $(OBJDIR)/system.img $(TOOLS)/build $(BOOT)/bootsect $(BOOT)/setup
	$(TOOLS)/build $(BOOT)/bootsect $(BOOT)/setup $< $(BOOTDEVICE) $@

# 'bootdisk.vmi' ist eine bootdisk, die auf 1.44 MB mit 0 aufgefuellt ist,
# damit VMware damit klarkommt.
$(OBJDIR)/bootdisk.vmi:  $(OBJDIR)/bootdisk.img
	dd if=$< of=$@ bs=1474560 conv=sync

# 'make depend' 
depend:
	$(DELETE) -f .depend
	$(CC) -MM $(CFLAGS) $(C_SOURCES) | sed -e "s|.*:|$(OBJDIR)\/&|" >> .depend
	$(CXX) -MM $(CFLAGS) $(CC_SOURCES) | sed -e "s|.*:|$(OBJDIR)\/&|" >> .depend

# 'make clean' loescht alle Objektdateien, das erzeugte System, Sicherheits-
# kopien des Editors und die Zwischendateien, die bei der Erzeugung von
# Objektdateien aus Assembler-Quelltexten temporaer entstehen.
clean:	
	@$(DELETE) -f $(OBJDIR)/*.[oO] $(OBJDIR)/*.img $(OBJDIR)/system *~ *.asp *.img
	@$(DELETE) -rf ./build

# 'make bootdisk' erzeugt zunaechst das System, falls das noch nicht geschehen
# ist. Danach wird eine Bootdiskette mit dem System erzeugt.
ifeq ($(GENSYS),Linux)
bootdisk: $(OBJDIR)/bootdisk.img
	cp $(OBJDIR)/bootdisk.img $(DRIVE)
else
bootdisk: $(OBJDIR)/bootdisk.img
	$(TOOLS)/rawrite -f $(OBJDIR)/bootdisk.img -d $(DRIVE) -n
endif

# 'build' tool compilieren.
$(TOOLS)/build: $(TOOLS)/build.c
	cd $(TOOLS) && $(TCC) -o $@ $<

# bootsector und protected mode setup code compilieren
$(BOOT)/bootsect $(BOOT)/setup: $(BOOT)/bootsect.asm $(BOOT)/setup.asm
	$(MAKE) -C $(BOOT)

# test des erstellten Systems
evaluate: $(OBJDIR)/bootdisk.img
	@../bochs/bochs.sh $(OBJDIR)/bootdisk.img
-include .depend
