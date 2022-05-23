1. 練習寫檔、開檔、關檔
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
