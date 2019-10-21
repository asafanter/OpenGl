#include <glad/glad.h>

#include "Mesh.h"

namespace GL {

Mesh::Mesh() :
    _vertices(),
    _indices(),
    _texture(),
    _vao(0),
    _vbo(0),
    _ebo(0),
    _model(glm::mat4(1.0)),
    _is_setup(false)
{

}

Mesh &Mesh::rotate(const real64 &x_deg, const real64 &y_deg, const real64 &z_deg)
{

    rotateX(x_deg);
    rotateY(y_deg);
    rotateZ(z_deg);

    return *this;
}

Mesh &Mesh::rotateX(const real64 &angle_deg)
{
    _model = glm::rotate(_model, REAL32(angle_deg), glm::vec3(1.0, 0.0, 0.0));

    return *this;
}

Mesh &Mesh::rotateY(const real64 &angle_deg)
{
    _model = glm::rotate(_model, REAL32(angle_deg), glm::vec3(0.0, 1.0, 0.0));

    return *this;
}

Mesh &Mesh::rotateZ(const real64 &angle_deg)
{
    _model = glm::rotate(_model, REAL32(angle_deg), glm::vec3(0.0, 0.0, 1.0));

    return *this;
}

Mesh &Mesh::scale(const real64 &x_scale, const real64 &y_scale, const real64 &z_scale)
{
    _model = glm::scale(_model, glm::vec3(x_scale, y_scale, z_scale));

    return *this;
}

Mesh &Mesh::scaleX(const real64 &factor)
{
    _model = glm::scale(_model, glm::vec3(factor, 1.0, 1.0));

    return *this;
}

Mesh &Mesh::scaleY(const real64 &factor)
{
    _model = glm::scale(_model, glm::vec3(1.0, factor, 1.0));

    return *this;
}

Mesh &Mesh::scaleZ(const real64 &factor)
{
    _model = glm::scale(_model, glm::vec3(1.0, 1.0, factor));

    return *this;
}

Mesh &Mesh::translate(const real64 &x_offset, const real64 &y_offset, const real64 &z_offset)
{
    _model = glm::translate(_model, glm::vec3(x_offset, y_offset, z_offset));

    return *this;
}

Mesh &Mesh::translateX(const real64 &offset)
{
    _model = glm::translate(_model, glm::vec3(offset, 0.0, 0.0));

    return *this;
}

Mesh &Mesh::translateY(const real64 &offset)
{
    _model = glm::translate(_model, glm::vec3(0.0, offset, 0.0));

    return *this;
}

Mesh &Mesh::translateZ(const real64 &offset)
{
    _model = glm::translate(_model, glm::vec3(0.0, 0.0, offset));

    return *this;
}

Mesh &Mesh::setPosition(const real64 &x, const real64 &y, const real64 &z)
{
    _model = glm::mat4(1.0);
    _model = glm::translate(_model, glm::vec3(x, y, z));

    return *this;
}

GL::Mesh &GL::Mesh::setup()
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    glBufferData(GL_ARRAY_BUFFER, INT64(_vertices.size() * sizeof(Vertex)), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INT64(_indices.size() * sizeof(uint32)),
                 _indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof (real32) * 3));
    glEnableVertexAttribArray(1);

    if(!_texture.isEmpty())
    {
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof (real32) * 7));
        glEnableVertexAttribArray(2);
    }

    glBindVertexArray(0);

    _is_setup = true;

    return *this;
}

void Mesh::remove()
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}

Mesh &Mesh::draw(const Program &program)
{
    if(!isSetupForDrawing())
    {
        return *this;
    }

    glBindVertexArray(_vao);

    trySetTexture();

    program.setMatrix4("model", _model);

    glDrawElements(GL_TRIANGLES, INT32(_indices.size()), GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    return *this;
}

bool Mesh::isSetupForDrawing() const
{
    if(!_is_setup)
    {
        std::cerr << "Mesh must be setup before drawing" << std::endl;
        return false;
    }

    if(_vertices.empty())
    {
        std::cerr << "vertices have not set" << std::endl;
        return false;
    }

    if(_vertices.empty())
    {
        std::cerr << "indices have not set" << std::endl;
        return false;
    }

    return true;
}

Mesh &Mesh::trySetTexture()
{
    glBindTexture(GL_TEXTURE_2D, _texture.getID());

    if(!_texture.isEmpty())
    {
        auto loc = glGetUniformLocation(1, "is_texture_set");
        glUniform1i(loc, 1);
    }
    else
    {
        auto loc = glGetUniformLocation(1, "is_texture_set");
        glUniform1i(loc, 0);
    }

    return *this;
}


} //namespace GL

