@echo off
qmake "CONFIG+=debug" || echo ERROR && exit /b
make || echo ERROR && exit /b
cd debug
Junqi.exe
