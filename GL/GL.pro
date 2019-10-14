TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    GL.cpp \
    glad.c \
    Window.cpp \
    Color.cpp \
    Shader.cpp \
    VertexShader.cpp \
    FragmentShader.cpp \
    Program.cpp \
    VAO.cpp \
    Vertex.cpp \
    VBO.cpp \
    Attribute.cpp


unix|win32: LIBS += -L$$PWD/bin/ -lglfw3dll

INCLUDEPATH += $$PWD/bin
DEPENDPATH += $$PWD/bin

INCLUDEPATH += $$PWD/bin/include

HEADERS += \
    Window.h \
    GL.h \
    GL_types.h \
    Color.h \
    Shader.h \
    VertexShader.h \
    FragmentShader.h \
    Program.h \
    VAO.h \
    Vertex.h \
    VBO.h \
    Attribute.h

DISTFILES += \
    Vertex.vsh \
    Fragment.fsh

