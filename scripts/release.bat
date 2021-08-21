@echo off
qmake || echo ERROR && exit /b
make || echo ERROR && exit /b
cd release
rmdir /s/q deploy
mkdir deploy
copy Junqi.exe deploy\Junqi.exe
cd deploy
windeployqt Junqi.exe
