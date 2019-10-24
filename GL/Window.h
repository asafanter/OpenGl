#ifndef WINDOW_H
#define WINDOW_H

#include <glfw3.h>
#include <string>
#include <functional>

#include "GL_types.h"
#include "Color.h"

namespace GL {

class Window
{
public:

    Window(const uint16& width = 800, const uint16& height = 600, const string& title = "window");
    Window(const uint16 &width, const uint16 &height, const string &title, const GL::Color &background_color);
    Window(const Window &window) = default;
    ~Window();
    Window &swapBuffers();
    Window &pollEvents();
    Window &setBackgroundColor(const real32& r, const real32& g, const real32& b, const real32& a);
    Window &setOnSizeChangedHandler(std::function<void(uint32, uint32)> handler);
    Window &setOnKeyPressedHandler(std::function<void(int32, int32)> handler);
    Window &setOnMouseMovedHandler(std::function<void(real64, real64)> handler);
    Window &setOnMouseClickedHandler(std::function<void(int32, int32)> handler);
    Window &setOnMouseScrolldHandler(std::function<void(real64)> handler);
    Window close();
    const Window &maximize() const;
    Window &setBackgroundColor(const Color &color) {_background_color = color; return *this;}
    Color getBackgroundColor() const {return _background_color;}
    uint16 getWidth() const;
    uint16 getHeight() const;
    string getTitle() const {return _title;}
    bool isOpen() const {return _is_open;}
    Window &setTitle(const string &new_title) {_title = new_title; return *this;}
    Window &setWidth(const uint16 &new_width);
    Window &setHeight(const uint16 &new_height);

private: //methods

    Window &init();
    Window &initGlad();
    Window &createWindow(const uint16 &width, const uint16 &height, const string &title);
    static void onSizeChanged(GLFWwindow* window, int32 width, int32 height);
    static void onKeyPressed(GLFWwindow* window, int32 key, int32 scancode, int32 action, int32 mods);
    static void onMouseMoved(GLFWwindow* window, real64 x, real64 y);
    static void onMouseClicked(GLFWwindow* window, int32 button, int32 action, int32 mods);
    static void onMouseScroll(GLFWwindow* window, real64 x_offset, real64 y_offset);

private: //members

    GLFWwindow* _window;
    Color _background_color;
    string _title;
    bool _is_open;
    static std::function<void(uint32, uint32)> _handler_size_changed;
    static std::function<void(int32, int32)> _handler_key_pressed;
    static std::function<void(real64, real64)> _on_mouse_moved;
    static std::function<void(int32, int32)> _on_mouse_clicked;
    static std::function<void(real64)> _on_mouse_scroll;
};


} //namespace GL

#endif // WINDOW_H
