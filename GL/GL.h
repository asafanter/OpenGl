#ifndef GL_H
#define GL_H

#include <vector>

#include "Window.h"
#include "Vertex.h"

namespace GL {

class GL
{
public:
    GL();
    GL &attachWindow(Window &window);
    GL &copyDataToGPU(const std::vector<Vertex> &vertices);
    void run();

private:
    Window* _window;
};
}

#endif // GL_H
