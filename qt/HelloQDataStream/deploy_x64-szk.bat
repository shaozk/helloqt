@echo off
::临时添加环境变量（32位Qt的windeployqt.exe安装目录，请拷贝该文件然后自己修改）
set path=D:\uidq5675\program\Qt\5.15.2\msvc2019_64\bin;%path%

set app=HelloQDataStream.exe

::调试和发布软件
set appList=%cd%\out\build\x64-Debug\%app% %cd%\out\build\x64-Release\%app%

::逐一部署
for %%i in (%appList%) do (
    windeployqt.exe %%i
)

pause

