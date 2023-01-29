/* JBYL
 * 
 * include/jbylc.h
 */

#include "jbyl.h"

#ifndef _JBYLC_H
#define _JBYLC_H

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

#define MAX_FILE_SIZE __INT_MAX__

/* errors.c */
void error(int s);

/* instch.c */
char insts[256];
int find_inst(char inst);

#endif
