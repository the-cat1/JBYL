/* JBYL
 * 
 * jbylc/errors.c
 * 抛出错误。
 */

#include <stdlib.h>
#include <stdio.h>

#include "jbylc.h"


/* 抛出一个错误 “s” 并退出 */ 
void error(int s)
{
    static char *error_msgs[] = {
        "Cannot open soure file.",
        "Soure file ext error.Ext of 'jbyl' file is '.jby' .",
        "Cannot open bytecode file.",
        "Unknown char.",
        "Cannot create tmp file.",
        "'-o' value syntax error.You can try 'jbylc --help'.",
        "Unknown.You can try 'jbylc --help'.",
        "Too big script."
    };
    
    puts(error_msgs[-(s+1)]);
    exit(s);
}
