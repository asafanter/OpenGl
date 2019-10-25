#include "TexturedVertex.h"

namespace GL {

TexturedVertex::TexturedVertex(const real32 &x, const real32 &y, const real32 &z,
                               const real32 &x_texture, const real32 &y_texture) :
    Vertex (x, y, z),
    _x_texture(x_texture),
    _y_texture(y_texture)
{

}

Vertex &TexturedVertex::setTextureCoords(const real32 &new_x, const real32 &new_y)
{
    _x_texture = new_x;
    _y_texture = new_y;

    return *this;
}


} //namespace GL

