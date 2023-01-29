/* JBYL
 * 
 * jbylc.c
 * 编译.jby文件，变成.jbc文件。
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "hmsgs.h"
#include "jbylc.h"

int main(int argc, char const *argv[])
{
    if (argc <= 1 || !strcmp(argv[1], "--help")) {
        puts(JBYLC_HMSG);
        return 1;
    }

    /* 文件后缀名 */
    char *ext = strchr(argv[1], '.');
    if (ext == NULL || strcmp(ext, ".jby")) error(-2);

    /* 判断参数 */
    char bcfname[FILENAME_MAX] = "a.jbc";
    int i;
    for (i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "-o")) {
            if (i+1 == argc) error(-7);
            strcpy(bcfname, argv[++i]);
        } else error(-7);
    }

    /* 创建临时文件 */
    FILE *ctemp = tmpfile();
    if (ctemp == NULL) error(-5);

    /* 打开文件 */
    FILE *script = fopen(argv[1],"r");
    if (script == NULL) error(-1);
    
    /* 编译源文件到ctemp里 */
    char inst = fgetc(script);
    while (inst != EOF) {
        if (inst != '\n' && inst != '\r' &&
            inst != '\t' && inst != ' '  && inst != '#') {
            int binst = find_inst(inst);
            if (binst == -1)                // 指令不存在
                error(-4);
            else
                putc(binst, ctemp);
        } else if (inst == '#') {           // 注释
            inst = getc(script);
            while (inst != '#')
                inst = getc(script);
        }
        
        inst = fgetc(script);
    }
    fclose(script);

    /* 文件大小 */
    int fsize = ftell(ctemp);
    if (fsize > MAX_FILE_SIZE) error(-8);

    /* 打开文件 */
    FILE *bcf = fopen(bcfname, "wb");
    if (bcf == NULL) error(-3);

    /* 写入文件头 */
    struct JBYLFileHead fhead = {
        'J', 'B', 'Y', 'L',
        VER_X, VER_Y, VER_Z,
        fsize
    };
    fwrite(&fhead, sizeof(fhead), 1, bcf);
    
    /* 复制字节码 */
    rewind(ctemp);
    char ch = fgetc(ctemp);
    while (ch != EOF) {
        fputc(ch, bcf);
        ch = fgetc(ctemp);
    }

    fclose(bcf);
    fclose(ctemp);
    return 0;
}
