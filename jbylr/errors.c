/* JBYL
 * 
 * jbylr/errors.c
 * 抛出错误。
 */

#include <stdlib.h>
#include <stdio.h>

#include "jbylr.h"


/* 抛出一个错误 “s” 并退出 */
void error(int s)
{
    char *error_msgs[] = {
        "Cannot open bytecode file.",
        "Ext of JBYL bytecode is '.jbc'.",
        "Bytecode syntax error.Use JBYLC to make it(see 'jbylc --help').",
        "Unknown bytecode."
    };

    puts(error_msgs[-(s+1)]);
    exit(s);
}
