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
    teacher.cpp \
    externalteacher.cpp \
    internalteacher.cpp \
    datas.cpp

HEADERS += \
    campus.hpp \
    student.hpp \
    school.hpp \
    campusmanager.hpp \
    teacher.hpp \
    externalteacher.hpp \
    internalteacher.hpp \
    fullcampusException.hpp \
    constants.hpp \
    datas.hpp
