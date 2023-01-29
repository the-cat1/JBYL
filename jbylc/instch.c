/* JBYL
 * 
 * jbylc/instch.c
 * 定义了所有指令对应的字符。
 */

#include "jbylc.h"

char insts[256] = {
    ',', 'v',
    'a', 'b', 'c',
    '+', '-'
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