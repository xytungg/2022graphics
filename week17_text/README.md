# week17
期末作品講解
## 1.環境建置
### a. 開啟CodeBlocks-新增Glut專案
### b. 開啟Setting-Compiler 
  =>確認Search directories 是否有Add 「C:\OpenCV2.1\include」
  =>確認Linker settings 是否有Add 「cv210」、「cxcore210」、「highgui210」
### c. 開啟當日新增的專案資料夾-用滑鼠右鍵點選Nopad++開啟當日cbp檔案
  =>將working_dir後引號內改成「.」(11行和21行)
### d. 將freeglut.dll複製丟進當日資料夾
### e. 在當日資料夾新增data資料夾，將分割好的obj檔和mtl檔丟入
### f. Glut專案初始程式碼
