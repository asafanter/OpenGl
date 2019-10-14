#ifndef GL_H
#define GL_H

#include <vector>

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
    GL &bindVAO(const VAO &vao);
    GL &bindVBO(const VBO &vbo);
    void run(const Program &program);
    ~GL();

private: //methods
    GL &draw(const VAO &vao);

private: //members
    Window* _window;
    std::vector<VAO> _vaos;
};

} //namespace GL

#endif // GL_H
