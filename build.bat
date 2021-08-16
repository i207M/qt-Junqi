@REM @echo off
qmake "CONFIG+=debug"
make
cd debug
export QT_LOGGING_RULES="*.debug=true"
Hello.exe
