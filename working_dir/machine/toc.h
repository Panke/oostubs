/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 T O C                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __toc_include__
#define __toc_include__

/**
 * The structure toc or better 'thread of control' is used to save the values of
 * the non-volatile registers if a context switch occurs. EAX, ECX and EDX are 
 * volatile registers if the GNU C compiler is used. Their values are can be 
 * lost after a switch of context.
 *
 * Attention: To enable the access to the elements using an assemblermethod the
 * offsets of the elements are defined in file 'toc.inc'. The order of the 
 * defined elements of the structure has to correspond to the defined offsets in 
 * 'toc.inc'. If the definition of toc is changed the definitions in 'toc.inc' 
 * have to be changed as well.
 */
struct toc {
  void *ebx;
  void *esi;
  void *edi;
  void *ebp;
  void *esp;
};

#endif
