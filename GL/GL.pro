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
    Texture.cpp \
    Mesh.cpp \
    TexturedVertex.cpp \
    ColoredVertex.cpp \
    Vertex.cpp \
    ColoredBuffer.cpp \
    TexturedBuffer.cpp

INCLUDEPATH += $$PWD/bin
DEPENDPATH += $$PWD/bin

INCLUDEPATH += \
    $$PWD/bin/include \
    $$PWD/bin/include/glm-0.9.2.7 \

HEADERS += \
    Window.h \
    GL.h \
    GL_types.h \
    Color.h \
    Shader.h \
    VertexShader.h \
    FragmentShader.h \
    Program.h \
    Texture.h \
    Mesh.h \
    TexturedVertex.h \
    ColoredVertex.h \
    Vertex.h \
    ColoredBuffer.h \
    Buffer.h \
    TexturedBuffer.h

DISTFILES += \
    Vertex.vsh \
    Fragment.fsh


unix|win32: LIBS += -L$$PWD/./ -lglfw3dll

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
