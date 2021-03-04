TEMPLATE = lib

QT -= gui
QT += xml

TARGET = ach2

DESTDIR = $$(RRS_DEV_ROOT)/modules/$$join(TARGET,,,)

LIBS += -L$$(RRS_DEV_ROOT)/bin -lCfgReader
LIBS += -L$$(RRS_DEV_ROOT)/bin -lphysics
LIBS += -L$$(RRS_DEV_ROOT)/bin -lvehicle
LIBS += -L$$(RRS_DEV_ROOT)/bin -ldevice
LIBS += -L$$(RRS_DEV_ROOT)/bin -lfilesystem

INCLUDEPATH += ./include
INCLUDEPATH += $$(RRS_DEV_ROOT)/sdk/include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)
