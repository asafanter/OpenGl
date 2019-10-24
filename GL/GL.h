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
        glm::vec3 right;
        real64 yaw;
        real64 pitch;
        real64 roll;
        real64 fov;
        bool is_fov_changed;
        const real64 MAX_PITCH_ANGLE_DEG = 89.0;
    };

    struct Mouse
    {
        bool is_new_movement;
        bool is_left_button_pressed;
        bool is_right_button_pressed;
        real64 last_x;
        real64 last_y;
        const real64 sensitivity = 0.01;
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
    GL &setMouseClickedHandler();
    GL &setMouseScrollHandler();
    GL &init();
    GL &initCamera();
    GL &initKeys();
    GL &handleInput();
    real64 limitAngle(const real64 &angle_deg, const real64 &min, const real64 &max);
    GL &updateView();
    GL &updateProjection();
    GL &setMatricesToProgram(const Program &program);

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
