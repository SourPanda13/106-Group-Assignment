QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountdetails.cpp \
    adminhome.cpp \
    adminmainpage.cpp \
    booktest.cpp \
    bookvax.cpp \
    contactus.cpp \
    login.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    reportissue.cpp \
    signup.cpp \
    userlist.cpp \
    vaxcertreq.cpp

HEADERS += \
    accountdetails.h \
    adminhome.h \
    adminmainpage.h \
    booktest.h \
    bookvax.h \
    contactus.h \
    login.h \
    mainpage.h \
    mainwindow.h \
    reportissue.h \
    signup.h \
    userlist.h \
    vaxcertreq.h

FORMS += \
    accountdetails.ui \
    adminhome.ui \
    adminmainpage.ui \
    booktest.ui \
    bookvax.ui \
    contactus.ui \
    login.ui \
    mainpage.ui \
    mainwindow.ui \
    reportissue.ui \
    signup.ui \
    userlist.ui \
    vaxcertreq.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QR_Codes.qrc

DISTFILES += \
    ../../../../../../../Desktop/QR Code/Book vax.png \
    QR Code/Book vax.png \
    QR Code/Book vax.png
