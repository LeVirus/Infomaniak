TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -ltinyxml

SOURCES += main.cpp \
    campus.cpp \
    student.cpp \
    school.cpp \
    campusmanager.cpp \
    studentsmanager.cpp \
    teacher.cpp \
    externalteacher.cpp \
    internalteacher.cpp \
    teachermanager.cpp \
    datas.cpp

HEADERS += \
    campus.hpp \
    student.hpp \
    school.hpp \
    campusmanager.hpp \
    studentsmanager.hpp \
    teacher.hpp \
    externalteacher.hpp \
    internalteacher.hpp \
    teachermanager.hpp \
    fullcampusException.hpp \
    constants.hpp \
    datas.hpp
