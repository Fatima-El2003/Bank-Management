QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    credit.cpp \
    creditAconsomation.cpp \
    creditEtudiant.cpp \
    creditImmobilier.cpp \
    main.cpp \
    mainwindow.cpp \
    rembourser.cpp \
    rembourserCache.cpp \
    rembourserEnLigne.cpp

HEADERS += \
    client.h \
    credit.h \
    creditAconsomation.h \
    creditEtudiant.h \
    creditImmobilier.h \
    mainwindow.h \
    rembourser.h \
    rembourserCache.h \
    rembourserEnLigne.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
