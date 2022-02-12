QT += gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Cover.cpp \
        main.cpp

VERSION = 0.2
QMAKE_TARGET_COMPANY = "romanmatv"
QMAKE_TARGET_DESCRIPTION = "Music cover extractor&compressor for players"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2022, romanmatv"
QMAKE_TARGET_PRODUCT = "MusicCoverCompress"

RC_ICONS = compress.ico

#message($$PWD)

INCLUDEPATH += $$PWD/taglib-msvc/include
LIBS += -L$$PWD/taglib-msvc/lib -ltag

#QMAKE_CXXFLAGS_RELEASE += -Ofast -MT
#QMAKE_CFLAGS_RELEASE += -Ofast -MT

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Cover.h
