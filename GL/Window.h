#ifndef WINDOW_H
#define WINDOW_H

#include <glfw3.h>
#include <string>

namespace GL {

using string = std::string;
using uint = unsigned int;

class Window
{
public:

    struct Color
    {
        float r;
        float g;
        float b;
        float a;
    };

    Window(const uint& width = 800, const uint& height = 600, const string& title = "window");
    ~Window();
    Window &setBackgroundColor(const float& r, const float& g, const float& b, const float& a);
    bool isRunning() const;
    Color getBackgroundColor() const {return _background_color;}
    GLFWwindow* getWindow() {return _window;}

private: //methods

    Window& init();
    Window& initGlad();
    Window &createWindow(const uint& width, const uint& height, const string& title);
    Window& onSizeChanged();

private: //members

    GLFWwindow* _window;
    Color _background_color;
};
}

#endif // WINDOW_H
