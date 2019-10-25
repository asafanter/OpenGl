#include <glad/glad.h>

#include "TexturedBuffer.h"

namespace GL {

TexturedBuffer::TexturedBuffer() :
    _vertices(),
    _texture()
{

}

void GL::TexturedBuffer::setupVertices() const
{
    glBufferData(GL_ARRAY_BUFFER, INT64(_vertices.size() * sizeof(TexturedVertex)), _vertices.data(), GL_STATIC_DRAW);
}

void TexturedBuffer::setupAttributes() const
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), reinterpret_cast<void*>(sizeof(Vertex)));
    glEnableVertexAttribArray(2);
}

TexturedBuffer &TexturedBuffer::setTexture(const Texture &texture)
{
    _texture = texture;

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

