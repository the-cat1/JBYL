/* JBYL
 * 
 * include/instbc.h
 * 定义了所有指令的字节码。
 */

#ifndef _INSTBC_H
#define _INSTBC_H

#define IBC_NONE        0x00
#define IBC_VERSION     0x01
#define IBC_PUSH_A      0x02
#define IBC_PUSH_B      0x03
#define IBC_PUSH_C      0x04
#define IBC_ADD_1       0x05
#define IBC_SUB_1       0x06
#define IBC_POP_A       0x07
#define IBC_POP_B       0x08
#define IBC_POP_C       0x09
#define IBC_PUT_CHAR    0x0a
#define IBC_PUT_STRING  0x0b
#define IBC_DEBUG       0x0c

#endif
