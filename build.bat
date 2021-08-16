@echo off
qmake "CONFIG+=debug"
make
cd debug
Hello.exe
