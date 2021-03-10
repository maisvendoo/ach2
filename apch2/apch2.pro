TEMPLATE = lib

QT -= gui
QT += xml

TARGET = apch2

# RRS_ROOT - путь к корневому каталогу симулятора! RRS_DEV_ROOT - прихоть maisvendoo
DESTDIR = $$(RRS_DEV_ROOT)/modules/$$join(TARGET,,,)

LIBS += -L$$(RRS_DEV_ROOT)/bin -lCfgReader
LIBS += -L$$(RRS_DEV_ROOT)/bin -lphysics
LIBS += -L$$(RRS_DEV_ROOT)/bin -lvehicle
LIBS += -L$$(RRS_DEV_ROOT)/bin -ldevice
LIBS += -L$$(RRS_DEV_ROOT)/bin -lfilesystem

INCLUDEPATH += $$(RRS_DEV_ROOT)/sdk/include
INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)
