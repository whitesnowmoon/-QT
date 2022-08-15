QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Disk.cpp \
    FPage.cpp \
    File.cpp \
    FileM.cpp \
    Filemanage.cpp \
    dmenu.cpp \
    main.cpp \
    mainwindow.cpp \
    pbutton.cpp \
    pmenu.cpp \
    weidt.cpp \
    wigdetdisk.cpp \
    wigdetpage.cpp

HEADERS += \
    Disk.h \
    FPage.h \
    File.h \
    FileM.h \
    Filemanage.h \
    Profiles.h \
    dmenu.h \
    mainwindow.h \
    pbutton.h \
    pmenu.h \
    weidt.h \
    wigdetdisk.h \
    wigdetpage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
