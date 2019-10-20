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
    Vertex.cpp \
    Texture.cpp \
    Mesh.cpp


unix|win32: LIBS += -L$$PWD/bin/ -lglfw3dll

INCLUDEPATH += $$PWD/bin
DEPENDPATH += $$PWD/bin

INCLUDEPATH += \
    $$PWD/bin/include \
    C:/Users/asafanter/Desktop/glm-0.9.2.7 \

HEADERS += \
    Window.h \
    GL.h \
    GL_types.h \
    Color.h \
    Shader.h \
    VertexShader.h \
    FragmentShader.h \
    Program.h \
    Vertex.h \
    Texture.h \
    Mesh.h

DISTFILES += \
    Vertex.vsh \
    Fragment.fsh

