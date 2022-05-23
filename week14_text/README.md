1. 練習開檔、寫檔、關檔
```c
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");
    printf("Hello World\n"); ///小黑視窗
    fprintf(fout, "Hello World\n"); ///txt
    fclose(fout);
}
```
2. 練習開檔、讀檔、關檔
```c
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout, "angle1 %d\n", 999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);
    printf("讀到了字串:%s 及整數%d\n", line, a);
    fclose(fin);
}
```
