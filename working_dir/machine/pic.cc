/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I C                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "pic.h"
#include "machine/io_port.h"
#include "machine/cpu.h"

extern CPU cpu;

PIC::PIC() : imr_a(0x21), imr_b(0xa1), isr_a(0x20), isr_b(0xa0) {}

void PIC::allow(PIC::Device dev)
{
	// check which pic manages the interrupt
	cpu.enable_int();
	short pin = 1 << dev;
	char old_imr = imr_a.inb();
	old_imr = old_imr & (~pin);
	imr_a.outb(old_imr);


	old_imr = imr_b.inb();
	old_imr = old_imr & (~(pin >> 8));
	imr_b.outb(old_imr);
}


void PIC::forbid(PIC::Device dev) 
{
	short pin = 1 << dev;
	char old_imr = imr_a.inb();
	old_imr = old_imr | pin;
	imr_a.outb(old_imr);

	old_imr = imr_b.inb();
	old_imr = old_imr |( pin >> 8);
	imr_b.outb(old_imr);
}

void PIC::ack()
{
	isr_a.outb(PIC::ACK);
	isr_b.outb(PIC::ACK);
}



