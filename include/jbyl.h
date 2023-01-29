/* JBYL
 * 
 * include/jbyl.h
 */

#ifndef _JBYL_H
#define _JBYL_H

typedef unsigned char byte;

struct JBYLFileHead {
    char J,B,Y,L;
    byte cVerX, cVerY, cVerZ;               // JBYLR的版本号
    int fsize;
};

#endif
