QT = core gui network widgets

CONFIG += c++17 cmdline

#msvc {
#QMAKE_CFLAGS += /utf-8
#QMAKE_CXXFLAGS += /utf-8
#}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bx_y1a.cpp \
        filemonitoring.cpp \
        filemonitoringworker.cpp \
        main.cpp \
        mainclass.cpp \
        myudpserver.cpp \
        novacontroller.cpp \
        novacontrollerworker.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    NovaHeader.h \
    YQNetCom.h \
    bx_y1a.h \
    filemonitoring.h \
    filemonitoringworker.h \
    mainclass.h \
    myudpserver.h \
    novacontroller.h \
    novacontrollerworker.h

unix:!macx: LIBS += -L$$PWD/lib/ -lboost_date_time

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/ -lboost_filesystem

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/ -lboost_system

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/ -lboost_thread

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/ -lcurl

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/ -lfun

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/Nova/ -lNovaTraffic

INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src
