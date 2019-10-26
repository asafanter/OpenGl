#include "TexturedVertex.h"

namespace GL {

TexturedVertex::TexturedVertex(const real64 &x, const real64 &y, const real64 &z,
                               const real64 &x_texture, const real64 &y_texture) :
    Vertex (x, y, z),
    _x_texture(REAL32(x_texture)),
    _y_texture(REAL32(y_texture))
{

}

Vertex &TexturedVertex::setTextureCoords(const real64 &new_x, const real64 &new_y)
{
    _x_texture = REAL32(new_x);
    _y_texture = REAL32(new_y);

    return *this;
}


} //namespace GL

