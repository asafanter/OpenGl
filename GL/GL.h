#ifndef GL_H
#define GL_H

#include <vector>
#include <memory>

#include "Window.h"
#include "Shader.h"
#include "Program.h"
#include "VAO.h"

namespace GL {

class GL
{
public:
    GL();
    GL &attachWindow(Window &window);
    GL &addVAO(const VAO &vao);
    GL &setPointSize(const uint32 &size);
    GL &setLineWidth(const uint32 &width);
    bool hasVAO() const {return _vaos.size() > 0;}
    void run(const Program &program);
    ~GL();

private: //methods
    GL &draw(const VAO &vao);
    GL &drawPoints(const uint64 &num_of_vertices);
    GL &drawLines(const uint64 &num_of_vertices);
    GL &drawTriangles(const uint64 &num_of_vertices);

private: //members
    Window* _window;
    std::vector<VAO> _vaos;
};

} //namespace GL

#endif // GL_H
