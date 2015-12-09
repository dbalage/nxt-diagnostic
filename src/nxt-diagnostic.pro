TEMPLATE = app

CONFIG += c++14
QMAKE_CXXFLAGS_CXX11 = -std=c++1y

QT += qml quick widgets

SOURCES += main.cpp \
    nxt_lib/adc_8591.cpp \
    nxt_lib/bluetooth.cpp \
    nxt_lib/brick.cpp \
    nxt_lib/color.cpp \
    nxt_lib/compass.cpp \
    nxt_lib/error.cpp \
    nxt_lib/filesystem.cpp \
    nxt_lib/i2c.cpp \
    nxt_lib/io_8574.cpp \
    nxt_lib/motor.cpp \
    nxt_lib/network.cpp \
    nxt_lib/sensor.cpp \
    nxt_lib/sonar.cpp \
    nxt_lib/tilt.cpp \
    Nxt.cpp \
    NxtApplication.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    nxt_lib/adc_8591.h \
    nxt_lib/bluetooth.h \
    nxt_lib/brick.h \
    nxt_lib/color.h \
    nxt_lib/compass.h \
    nxt_lib/connection.h \
    nxt_lib/error.h \
    nxt_lib/filesystem.h \
    nxt_lib/gyro.h \
    nxt_lib/i2c.h \
    nxt_lib/io_8574.h \
    nxt_lib/light.h \
    nxt_lib/motor.h \
    nxt_lib/network.h \
    nxt_lib/nxt.h \
    nxt_lib/rcx_light.h \
    nxt_lib/rotation.h \
    nxt_lib/sensor.h \
    nxt_lib/sonar.h \
    nxt_lib/sound.h \
    nxt_lib/temperature.h \
    nxt_lib/tilt.h \
    nxt_lib/touch.h \
    Nxt.h \
    NxtApplication.h

LIBS += -lws2_32
