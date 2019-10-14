TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    GL.cpp \
    glad.c \
    Window.cpp \
    Shader.cpp \
    VertexShader.cpp \
    FragmentShader.cpp \
    Program.cpp


unix|win32: LIBS += -L$$PWD/bin/ -lglfw3dll

INCLUDEPATH += $$PWD/bin
DEPENDPATH += $$PWD/bin

INCLUDEPATH += $$PWD/bin/include

HEADERS += \
    Window.h \
    Shader.h \
    VertexShader.h \
    FragmentShader.h \
    Program.h \
    GL.h \
    Vertex.h

