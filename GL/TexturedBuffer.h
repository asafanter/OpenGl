#ifndef TEXTUREDBUFFER_H
#define TEXTUREDBUFFER_H

#include <vector>

#include "Buffer.h"
#include "TexturedVertex.h"
#include "Texture.h"

namespace GL {

class TexturedBuffer : public Buffer
{
public:
    TexturedBuffer();
    TexturedBuffer &addVertex(const TexturedVertex &vertex) {_vertices.emplace_back(vertex); return *this;}
    TexturedBuffer &setVertices(const std::vector<TexturedVertex> &new_vertices) {_vertices = new_vertices; return *this;}
    virtual void setupVertices() const;
    virtual void setupAttributes() const;
    TexturedBuffer &setTexture(const Texture &texture);

private:
    std::vector<TexturedVertex> _vertices;
    Texture _texture;
};

} //namespace GL



#endif // TEXTUREDBUFFER_H
