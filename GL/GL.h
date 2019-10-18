#ifndef GL_H
#define GL_H

#include <vector>
#include <memory>

#include "Window.h"
#include "Shader.h"
#include "Program.h"
#include "VAO.h"
#include "VBO.h"

namespace GL {

class GL
{
public:
    GL();
    GL &attachWindow(Window &window);
    GL &compileShader(const Shader &shader);
    GL &linkProgram(const Program &program);
    GL &addVAO(const VAO &vao);
    GL &setPointSize(const uint32 &size);
    GL &setLineWidth(const uint32 &width);
    bool hasVAO() const {return _vaos.size() > 0;}
    void run();
    ~GL();

private: //methods
    GL &draw(const VAO &vao);
    GL &bindVAO(const VAO &vao);

private: //members
    Window* _window;
    std::vector<VAO> _vaos;
    std::shared_ptr<Program> _program;
};

} //namespace GL

#endif // GL_H
