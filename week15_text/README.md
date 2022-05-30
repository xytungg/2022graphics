# week15
1. 播放聲音
```c
///#include <mmsystem.h>//上週教
#include <windows.h>///另一種寫法，結果一樣
int main()
{           ///先放不存在的檔     上週教SND_ASYNC
    PlaySound("badbadbad.wav", NULL, SND_SYNC);
}///Compile成功，但是link失敗
/// .c .cpp =compile=> .o =link=> .exe
```
