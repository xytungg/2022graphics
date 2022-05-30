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
2. 播放想要的音效
```c
///#include <mmsystem.h>//上週教
#include <windows.h>///另一種寫法，結果一樣
int main()
{           ///先放不存在的檔     上週教SND_ASYNC
    PlaySound("badbadbad.wav", NULL, SND_SYNC); ///更改這行
}///Compile成功，但是link失敗
/// .c .cpp =compile=> .o =link=> .exe
```
3. 比較 SND_SYNC 和 SND_ASYNC
```c
#include <windows.h>
#include <stdio.h>///printf()
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav", NULL, SND_ASYNC);
    printf("現在在PlaySound()後\n");
    int N;
    scanf("%d", &N);///等你輸入數字
}
```
4. 播放mp3
```c
#include  "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("現在正在播放羊的聲音\n");
    int N;
    scanf("%d", &N);


}
```
