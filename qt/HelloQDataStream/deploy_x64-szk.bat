@echo off
::��ʱ��ӻ���������32λQt��windeployqt.exe��װĿ¼���뿽�����ļ�Ȼ���Լ��޸ģ�
set path=D:\uidq5675\program\Qt\5.15.2\msvc2019_64\bin;%path%

set app=HelloQDataStream.exe

::���Ժͷ������
set appList=%cd%\out\build\x64-Debug\%app% %cd%\out\build\x64-Release\%app%

::��һ����
for %%i in (%appList%) do (
    windeployqt.exe %%i
)

pause

