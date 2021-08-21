QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 Console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chessboard.cpp \
    clickablelabel.cpp \
    createserverdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    netboard.cpp \
    piece.cpp \
    piecedisplay.cpp

HEADERS += \
    m_debug.h \
    chessboard.h \
    clickablelabel.h \
    createserverdialog.h \
    mainwindow.h \
    netboard.h \
    piece.h \
    piecedisplay.h

FORMS += \
    createserverdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Chessboard.qrc
