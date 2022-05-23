#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");
    printf("Hello World\n"); ///¤p¶Âµøµ¡
    fprintf(fout, "Hello World\n"); ///txt
    fclose(fout);
}
