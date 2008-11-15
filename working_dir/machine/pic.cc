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
	IO_Port& p = dev > 128 ? imr_b : imr_a;
	cpu.enable_int();
	char old_imr = p.inb();
	// unset all bits in new_imr, that a set in dev
	char new_imr = old_imr & (~dev);
	p.outb(new_imr);

}


void PIC::forbid(PIC::Device dev) 
{
	IO_Port& p = dev > 128 ? imr_b : imr_a;
	char imr = p.inb();
	imr = imr | dev;
	p.outb(imr);
}

void PIC::ack()
{
	isr_a.outb(PIC::ACK);
	isr_b.outb(PIC::ACK);
}



