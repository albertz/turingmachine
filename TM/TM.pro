#-------------------------------------------------
#
# Project created by QtCreator 2010-08-19T13:55:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TM
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    NonDetTM.cpp \
    TMAction.cpp \
    TMActionInput.cpp \
    NonDetTMExecution.cpp \
    NonDetTMExecBranch.cpp

HEADERS += \
    NonDetTM.h \
    Number.h \
    TMAlphabet.h \
    TMAction.h \
    TMActionInput.h \
    TMTape.h \
    NonDetTMExecution.h \
    NonDetTMExecBranch.h
