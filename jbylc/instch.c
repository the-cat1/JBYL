/* JBYL
 * 
 * jbylc/instch.c
 * 定义了所有指令对应的字符。
 */

#include "jbylc.h"

char insts[256] = {
    ',' /* 0x00 */, 'v' /* 0x01 */,
    'a' /* 0x02 */, 'b' /* 0x03 */, 'c' /* 0x04 */,
    '+' /* 0x05 */, '-' /* 0x06 */,
    'A' /* 0x07 */, 'B' /* 0x08 */, 'C' /* 0x09 */,
    'p' /* 0x0a */, 'P' /* 0x0b */,
    'd' /* 0x0c */
};

/* 查找对应指令 */
int find_inst(char inst)
{
    int i;
    for (i = 0; i < 256; i++) {
        if (insts[i] == inst) {
            return i;
        }
    }
    // 指令不存在
    return -1;
}