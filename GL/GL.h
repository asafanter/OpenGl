#ifndef GL_H
#define GL_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "Shader.h"
#include "Program.h"
#include "Mesh.h"

namespace GL {

class GL
{
public:
    GL();
    GL &attachWindow(Window &window);
    GL &addMesh(const Mesh &mesh);
    GL &setPointSize(const uint32 &size);
    GL &setLineWidth(const uint32 &width);
    void run(const Program &program);
    ~GL();

private: //defs
    struct Camera
    {
        glm::vec3 pos;
        glm::vec3 front;
        glm::vec3 up;
    };

private: //methods
    GL &drawPoints(const uint64 &num_of_vertices);
    GL &drawLines(const uint64 &num_of_vertices);
    GL &drawTriangles(const uint64 &num_of_vertices);
    GL &clearBackgroundColor();
    GL &updateMatrices(const Program &program);

private: //members
    Window* _window;
    std::vector<Mesh> _meshes;
    glm::mat4 _view;
    glm::mat4 _projection;
    Camera _camera;
};

} //namespace GL

#endif // GL_H
