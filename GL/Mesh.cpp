#include <glad/glad.h>

#include "Mesh.h"
#include "TexturedBuffer.h"

namespace GL {

Mesh::Mesh() :
    _indices(),
    _vao(0),
    _vbo(0),
    _ebo(0),
    _model(glm::mat4(1.0)),
    _is_setup(false),
    _is_textured(false),
    _premitive(Premitive::TRIANGLES)
{

}

Mesh &Mesh::setupBuffer(const Buffer &buffer)
{
    const TexturedBuffer *textured_buffer = dynamic_cast<const TexturedBuffer*>(&buffer);
    _is_textured = textured_buffer != nullptr;

    if(_is_textured && textured_buffer->getTexture().isEmpty())
    {
        std::cerr << "buffer has no texture" << std::endl;
    }

    if(_indices.empty())
    {
        std::cerr << "must set indices before setup buffer" << std::endl;
    }

    if(buffer.getNumOfVertices() == 0)
    {
        std::cerr << "buffer has no vertices" << std::endl;
    }

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    buffer.setupVertices();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INT64(_indices.size() * sizeof(uint32)),
                 _indices.data(), GL_STATIC_DRAW);

    buffer.setupAttributes();

    glBindVertexArray(0);

    _is_setup = true;

    return *this;
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

    auto loc = glGetUniformLocation(program.getID(), "is_texture_set");
    if(_is_textured)
    {
        glBindTexture(GL_TEXTURE_2D, 2);

        glUniform1i(loc, 1);
    }
    else
    {
        glUniform1i(loc, 0);
    }

    program.setMatrix4("model", _model);

    drawPremitives();

    glBindVertexArray(0);

    if(_is_textured)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    return *this;
}

bool Mesh::isSetupForDrawing() const
{
    if(!_is_setup)
    {
        std::cerr << "Mesh must be setup before drawing" << std::endl;
        return false;
    }

    if(_indices.empty())
    {
        std::cerr << "indices have not set" << std::endl;
        return false;
    }

    return true;
}

Mesh &Mesh::drawPremitives()
{
    if(_premitive == Premitive::TRIANGLES)
    {
        glDrawElements(GL_TRIANGLES, INT32(_indices.size()), GL_UNSIGNED_INT, nullptr);
    }
    else if(_premitive == Premitive::LINES)
    {
        glDrawElements(GL_LINES, INT32(_indices.size()), GL_UNSIGNED_INT, nullptr);
    }
    else if(_premitive == Premitive::POINTS)
    {
        glDrawElements(GL_POINTS, INT32(_indices.size()), GL_UNSIGNED_INT, nullptr);
    }

    return *this;
}

} //namespace GL

