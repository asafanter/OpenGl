#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "GL.h"

namespace GL {

GL::GL() :
    _window(nullptr),
    _meshes(),
    _view(glm::mat4(1.0)),
    _projection(glm::mat4(1.0f)),
    _camera({}),
    _keys(NUM_OF_KEYS),
    _mouse({})
{
    init();
}

GL &GL::attachWindow(Window &window)
{
    _window = &window;
    setWindowHandlers();

    return *this;
}

GL &GL::addMesh(const Mesh &mesh)
{
    _meshes.emplace_back(mesh);

    return *this;
}

GL &GL::setPointSize(const uint32 &size)
{
    glPointSize(size);

    return *this;
}

GL &GL::setLineWidth(const uint32 &width)
{
    glLineWidth(width);

    return *this;
}

void GL::run(const Program &program)
{

    if(!isReadyForDrawing())
    {
        return ;
    }

    glEnable(GL_DEPTH_TEST);

    while(_window->isOpen())
    {
        clearBackgroundColor();


        program.use();

        handleInput();
        updateMatrices(program);

        for(auto &mesh : _meshes)
        {
//            mesh.rotateY(0.07);
            mesh.draw(program);
        }

        _window->swapBuffers();
        _window->pollEvents();
    }
}

GL::~GL()
{
    for(auto &mesh : _meshes)
    {
        mesh.remove();
    }
}

GL &GL::drawPoints(const uint64 &num_of_vertices)
{
    glDrawArrays(GL_POINTS, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::drawLines(const uint64 &num_of_vertices)
{
    if(num_of_vertices > 0 && num_of_vertices % 2 != 0)
    {
        std::cerr << "premitive set to 'lines' but num of vertices: " << num_of_vertices <<
                     " does not divide with 2" << std::endl;
    }

    glDrawArrays(GL_LINES, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::drawTriangles(const uint64 &num_of_vertices)
{
    if(num_of_vertices % 3 != 0)
    {
        std::cerr << "premitive set to 'triangles' but num of vertices: " << num_of_vertices <<
                     " does not divede with 3" << std::endl;
    }

    glDrawArrays(GL_TRIANGLES, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::clearBackgroundColor()
{
    Color color = _window->getBackgroundColor();
    glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return *this;
}

GL &GL::updateMatrices(const Program &program)
{
    updateView();
    updateProjection();
    setMatricesToProgram(program);

    return *this;
}

bool GL::isReadyForDrawing()
{
    if(_window == nullptr)
    {
        std::cerr << "there is no window attached" << std::endl;
        return false;
    }
    if(_meshes.empty())
    {
        std::cerr << "there is no meshes to draw" << std::endl;
        return false;
    }

    return true;
}

GL &GL::setWindowHandlers()
{
    setWindowsSizeChangedHandler();
    setKeyPressedHandler();
    setMouseMovedHandler();
    setMouseClickedHandler();
    setMouseScrollHandler();

    return *this;
}

GL &GL::setWindowsSizeChangedHandler()
{
    _window->setOnSizeChangedHandler([this](uint32 width, uint32 height)
    {
        _camera.is_fov_changed = true;
        glViewport(0, 0, INT32(width), INT32(height));
    });

    return *this;
}

GL &GL::setKeyPressedHandler()
{
    _window->setOnKeyPressedHandler([this](int32 key, int32 action)
    {
        if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            _window->close();
        }
        else
        {
            if(action == GLFW_PRESS)
            {
                _keys[UINT32(key)] = true;
            }

            if(action == GLFW_RELEASE)
            {
                _keys[UINT32(key)] = false;
            }
        }
    });

    return *this;
}

GL &GL::setMouseMovedHandler()
{
    _window->setOnMouseMovedHandler([this](real64 x, real64 y)
    {
        if(!_mouse.is_left_button_pressed)
        {
            return;
        }

        if(_mouse.is_new_movement)
        {
            _mouse.last_x = x;
            _mouse.last_y = y;
            _mouse.is_new_movement = false;
        }

        auto x_offset = _mouse.last_x - x;
        auto y_offset = _mouse.last_y - y;
        _mouse.last_x = x;
        _mouse.last_y = y;

        x_offset *= _mouse.sensitivity;
        y_offset *= -_mouse.sensitivity;



        if(_keys[GLFW_KEY_X])
        {
            _camera.pitch += limitAngle(y_offset * 5, -_camera.MAX_PITCH_ANGLE_DEG, _camera.MAX_PITCH_ANGLE_DEG);

            glm::dvec3 tmp_front;
            tmp_front.x = cos(glm::radians(_camera.yaw)) * cos(glm::radians(_camera.pitch));
            tmp_front.y = sin(glm::radians(_camera.pitch));
            tmp_front.z = sin(glm::radians(_camera.yaw)) * cos(glm::radians(_camera.pitch));
            _camera.front = glm::normalize(tmp_front);
        }
        else if(_keys[GLFW_KEY_Y])
        {
            _camera.yaw += x_offset * 5;

            glm::dvec3 tmp_front;
            tmp_front.x = cos(glm::radians(_camera.yaw)) * cos(glm::radians(_camera.pitch));
            tmp_front.y = sin(glm::radians(_camera.pitch));
            tmp_front.z = sin(glm::radians(_camera.yaw)) * cos(glm::radians(_camera.pitch));
            _camera.front = glm::normalize(tmp_front);
        }
        else
        {
            glm::vec3 offset(x_offset, y_offset, 0.0f);

            _camera.pos += offset;
        }





    });

    return *this;
}

GL &GL::setMouseClickedHandler()
{
    _window->setOnMouseClickedHandler([this](int32 button, int32 action)
    {
        if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            _mouse.is_new_movement = true;
            _mouse.is_left_button_pressed = true;
        }
        if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        {
            _mouse.is_left_button_pressed = false;
        }
        if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        {
            _mouse.is_right_button_pressed = true;
        }
        if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        {
            _mouse.is_right_button_pressed = false;
        }
    });

    return *this;
}

GL &GL::setMouseScrollHandler()
{
    _window->setOnMouseScrolldHandler([this](real64 offset)
    {
        if(_camera.fov >= 1.0 && _camera.fov <= 80.0)
        {
            _camera.fov -= offset;
            _camera.is_fov_changed = true;
        }

        if(_camera.fov <= 1.0)
        {
            _camera.fov = 1.0;
        }

        if(_camera.fov >= 80.0)
        {
            _camera.fov = 80.0;
        }
    });

    return *this;
}

GL &GL::init()
{
    initCamera();
    initKeys();

    return *this;
}

GL &GL::initCamera()
{
    _camera.pos = glm::vec3(0.0, 0.0, 3.0);
    _camera.front = glm::vec3(0.0, 0.0, -1.0);
    _camera.up = glm::vec3(0.0, 1.0, 0.0);
    _camera.right = glm::cross(_camera.front, _camera.up);
    _camera.yaw = -90.0;
    _camera.pitch = 0.0;
    _camera.roll = 0.0;
    _camera.fov = 45.0;
    _camera.is_fov_changed = true;

    return *this;
}

GL &GL::initKeys()
{
    for(auto key : _keys)
    {
        key = false;
    }

    return *this;
}

GL &GL::handleInput()
{
    if(_keys[GLFW_KEY_W])
    {
        _camera.pos += _camera.front * MOVEMENT_SPEED;
    }
    if(_keys[GLFW_KEY_S])
    {
        _camera.pos -= _camera.front * MOVEMENT_SPEED;
    }
    if(_keys[GLFW_KEY_A])
    {
        _camera.pos -= glm::normalize(glm::cross(_camera.front, _camera.up)) * MOVEMENT_SPEED;
    }
    if(_keys[GLFW_KEY_D])
    {
        _camera.pos += glm::normalize(glm::cross(_camera.front, _camera.up)) * MOVEMENT_SPEED;
    }

    return *this;
}

real64 GL::limitAngle(const real64 &angle_deg, const real64 &min, const real64 &max)
{
    auto res = angle_deg;

    if(res > max)
    {
        res = max;
    }

    if(res < min)
    {
        res = min;
    }

    return res;
}

GL &GL::updateView()
{
    _view = glm::lookAt(_camera.pos, _camera.pos + _camera.front, _camera.up);

    return *this;
}

GL &GL::updateProjection()
{
    if(_camera.is_fov_changed)
    {
        _projection = glm::perspective(REAL32(_camera.fov),
                                       REAL32(_window->getWidth()) / REAL32(_window->getHeight()), 0.1f, 100.0f);
        _camera.is_fov_changed = false;
    }

    return *this;
}

GL &GL::setMatricesToProgram(const Program &program)
{
    program.setMatrix4("view", _view);
    program.setMatrix4("projection", _projection);

    return *this;
}

} //namespace GL


