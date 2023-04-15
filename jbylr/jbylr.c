/* JBYL
 * 
 * jbylr.c
 * 运行编译好的.jbc字节码文件。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "hmsgs.h"
#include "jbylr.h"
#include "instbc.h"

int main(int argc, char const *argv[])
{
    if (argc <= 1 || !strcmp(argv[1], "--help")) {
        printf(JBYLR_HMSG);
        return 1;
    }

    /* 文件后缀名 */
    char *ext = strchr(argv[1], '.');
    if (ext == NULL || strcmp(ext, ".jbc")) error(-2);


    /* 打开文件 */
    FILE *bcf = fopen(argv[1], "rb");
    if (bcf == NULL) error(-1);

    struct JBYLFileHead fhead;
    fread(&fhead, sizeof(fhead), 1, bcf);

    if (fhead.J != 'J' || fhead.B != 'B' ||
        fhead.Y != 'Y' || fhead.L != 'L') {
        error(-3);
    }

    /* Stacks and variable */
    // Define
    Stack stackA, stackB, stackC;
    int var;
    // Initial
    init_stack(&stackA, fhead.fsize);
    init_stack(&stackB, 256);
    init_stack(&stackC, 256);
    var = 0;

    /* Read instructions */
    int bc = fgetc(bcf);
    while (bc != EOF) {
        push_stack(&stackA, bc);
        bc = fgetc(bcf);
    }
    fclose(bcf);
    
    /* Run bytecode */
    while (true) {
        if (allocad_stack(&stackA) == 0) break;
        int inst = pop_stack(&stackA);
        switch (inst)
        {
        case IBC_NONE:
            break;
        
        case IBC_VERSION:
            printf(VERSION_INFO);
            break;

        case IBC_PUSH_A:
            push_stack(&stackA, var);
            break;

        case IBC_PUSH_B:
            push_stack(&stackB, var);
            break;
        
        case IBC_PUSH_C:
            push_stack(&stackC, var);
            break;

        case IBC_ADD_1:
            var++;
            break;
        
        case IBC_SUB_1:
            var--;
            break;

        case IBC_POP_A:
            var = pop_stack(&stackA);
            break;
        
        case IBC_POP_B:
            var = pop_stack(&stackB);
            break;
        
        case IBC_POP_C:
            var = pop_stack(&stackC);
            break;
        
        case IBC_PUT_CHAR:
            putchar(var);
            break;
        
        case IBC_PUT_STRING: {
            int c = pop_stack(&stackB);
            while (c != '\0') {
                putchar(c);
                c = pop_stack(&stackB);
            }
            break;
        }
            
        case IBC_DEBUG:{
            int i;

            puts("---- DEBUG ----");
            
            puts("Stack A:");
            for (i = 0; i < allocad_stack(&stackA); i++)
                printf("    [%d] %d\n", i, stackA.data[i]);
            puts("Stack B:");
            for (i = 0; i < allocad_stack(&stackB); i++)
                printf("    [%d] %d\n", i, stackB.data[i]);
            puts("Stack C:");
            for (i = 0; i < allocad_stack(&stackC); i++)
                printf("    [%d] %d\n", i, stackC.data[i]);
            printf("Var: %d\n", var);
            
            puts("---- End of DEBUG ----");


            break;
        }

        default:
            error(-4);
        }
    }
    
    return 0;
}
