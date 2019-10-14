#ifndef WINDOW_H
#define WINDOW_H

#include <glfw3.h>
#include <string>

#include "GL_types.h"
#include "Color.h"

namespace GL {

class Window
{
public:

    Window(const uint16& width = 800, const uint16& height = 600, const string& title = "window");
    Window(const uint16 &width, const uint16 &height, const string &title, const Color &background_color);
    ~Window();
    bool isRunning() const;
    Window &swapBuffers();
    Window &pollEvents();
    Window &setBackgroundColor(const real32& r, const real32& g, const real32& b, const real32& a);
    Window &setBackgroundColor(const Color &color) {_background_color = color; return *this;}
    Color getBackgroundColor() const {return _background_color;}
    uint16 getWidth() const {return _width;}
    uint16 getHeight() const {return _height;}
    string getTitle() const {return _title;}


private: //methods

    Window& init();
    Window& initGlad();
    Window &createWindow(const uint16 &width, const uint16 &height, const string &title);
    static void onSizeChanged(GLFWwindow* window,  int32 width,  int32 height);

private: //members

    GLFWwindow* _window;
    Color _background_color;
    uint16 _width;
    uint16 _height;
    string _title;
};
}

#endif // WINDOW_H
