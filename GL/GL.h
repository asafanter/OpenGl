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

    const real32 MOVEMENT_SPEED = 0.005f;
    const uint32 NUM_OF_KEYS = 128;

    struct Camera
    {
        glm::vec3 pos;
        glm::vec3 front;
        glm::vec3 up;
        real64 yaw;
        real64 pitch;
        real64 roll;
        const real64 MAX_PITCH_ANGLE_DEG = 89.0;
    };

    struct Mouse
    {
        bool is_first_clicked;
        real64 curr_x;
        real64 curr_y;
        real64 last_x;
        real64 last_y;
        const real64 sensitivity = 0.08;
    };

private: //methods
    GL &drawPoints(const uint64 &num_of_vertices);
    GL &drawLines(const uint64 &num_of_vertices);
    GL &drawTriangles(const uint64 &num_of_vertices);
    GL &clearBackgroundColor();
    GL &updateMatrices(const Program &program);
    bool isReadyForDrawing();
    GL &setWindowHandlers();
    GL &setWindowsSizeChangedHandler();
    GL &setKeyPressedHandler();
    GL &setMouseMovedHandler();
    GL &init();
    GL &initCamera();
    GL &initKeys();
    GL &handleInput();
    real64 limitAngle(const real64 &angle_deg, const real64 &min, const real64 &max);

private: //members
    Window* _window;
    std::vector<Mesh> _meshes;
    glm::mat4 _view;
    glm::mat4 _projection;
    Camera _camera;
    std::vector<bool> _keys;
    Mouse _mouse;
};

} //namespace GL

#endif // GL_H
