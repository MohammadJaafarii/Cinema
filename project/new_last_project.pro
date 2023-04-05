QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book_progress_c.cpp \
    book_ticket.cpp \
    boss_entrance.cpp \
    boss_page.cpp \
    create_account.cpp \
    customer_page.cpp \
    editing.cpp \
    editing_progress.cpp \
    main.cpp \
    mainwindow.cpp \
    removing_movie.cpp \
    saving_movie.cpp \
    searching_page.cpp \
    second_page.cpp \
    show_history.cpp \
    showing.cpp \
    sign_in.cpp

HEADERS += \
    book_progress_c.h \
    book_ticket.h \
    boss_entrance.h \
    boss_page.h \
    create_account.h \
    customer_page.h \
    editing.h \
    editing_progress.h \
    mainwindow.h \
    removing_movie.h \
    saving_movie.h \
    searching_page.h \
    second_page.h \
    show_history.h \
    showing.h \
    sign_in.h

FORMS += \
    book_progress_c.ui \
    book_ticket.ui \
    boss_entrance.ui \
    boss_page.ui \
    create_account.ui \
    customer_page.ui \
    editing.ui \
    editing_progress.ui \
    mainwindow.ui \
    removing_movie.ui \
    saving_movie.ui \
    searching_page.ui \
    second_page.ui \
    show_history.ui \
    showing.ui \
    sign_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
