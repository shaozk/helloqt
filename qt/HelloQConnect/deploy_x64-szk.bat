@echo off
::��ʱ��ӻ���������32λQt��windeployqt.exe��װĿ¼���뿽�����ļ�Ȼ���Լ��޸ģ�
set path=D:\uidq5675\program\Qt\5.15.2\msvc2019_64\bin;%path%

set appName=HelloQConnect

::���Ժͷ������
set appList=%cd%\out\build\x64-Debug\%appName%.exe

::��һ����
for %%i in (%appList%) do (
    windeployqt.exe %%i
)

pause

