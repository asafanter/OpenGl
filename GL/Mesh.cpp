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
    _model(glm::mat4(1.0f))
{

}

Mesh &Mesh::rotate(const real32 &angle_deg, const RotationAxis &axis)
{
    if(axis == RotationAxis::X)
    {
        _model = glm::rotate(_model, angle_deg, glm::vec3(1.0f, 0.0f, 0.0f));
    }
    else if(axis == RotationAxis::Y)
    {
        _model = glm::rotate(_model, angle_deg, glm::vec3(0.0f, 1.0f, 0.0f));
    }
    else if(axis == RotationAxis::Z)
    {
        _model = glm::rotate(_model, angle_deg, glm::vec3(0.0f, 0.0f, 1.0f));
    }

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

    return *this;
}

void Mesh::remove()
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}

//TODO bring program as parameter
Mesh &Mesh::draw()
{

    if(_vertices.empty())
    {
        std::cerr << "vertices have not set" << std::endl;
        return *this;
    }

    if(_vertices.empty())
    {
        std::cerr << "indices have not set" << std::endl;
        return *this;
    }

    glBindTexture(GL_TEXTURE_2D, _texture.getID());

    glBindVertexArray(_vao);

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

    unsigned int modelLoc = glGetUniformLocation(1, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(_model));

    glDrawElements(GL_TRIANGLES, INT32(_indices.size()), GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);

    return *this;
}


} //namespace GL

