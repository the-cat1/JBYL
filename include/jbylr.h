/* JBYL
 * 
 * include/jbylr.h
 */

#include "jbyl.h"

#ifndef _JBYLR_H
#define _JBYLR_H

/* Version */
#ifndef VER_X
#define VER_X 0xFF
#endif
#ifndef VER_Y
#define VER_Y 0xFF
#endif
#ifndef VER_Z
#define VER_Z 0xFF
#endif

#define VERSION_INFO \
    "JBYLR Version %d.%d.%d\n"              \
    "Running file information:\n"           \
    "    File size:%d\n"                    \
    "    JBYLC Version %d.%d.%d\n",         \
    VER_X, VER_Y, VER_Z,                    \
    fhead.fsize,                            \
    fhead.cVerX, fhead.cVerY, fhead.cVerZ   \

/* errors.c */
void error(int s);

/* stack.c */
#define SF_DEFALUT  SF_EMPTY
#define SF_FULL     0x01
#define SF_EMPTY    0x00
typedef struct {
    int *data;
    int flags, len;
    int sp;
} Stack;
int init_stack(Stack *stack, int len);
int push_stack(Stack *stack, int data);
int pop_stack(Stack *stack);
int allocad_stack(Stack *stack);

#endif
