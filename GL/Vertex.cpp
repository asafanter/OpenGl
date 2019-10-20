#include "Vertex.h"

namespace GL {

Vertex::Vertex(const real32 &x, const real32 &y, const real32 &z, const Color &color, const real32 &x_texture, const real32 &y_texture) :
    _x(x),
    _y(y),
    _z(z),
    _color(color),
    _x_texture(x_texture),
    _y_texture(y_texture)
{

}

Vertex &Vertex::setCoords(const real32 &new_x, const real32 &new_y, const real32 &new_z)
{
    _x = new_x;
    _y = new_y;
    _z = new_z;

    return *this;
}

Vertex &Vertex::setTextureCoords(const real32 &new_x, const real32 &new_y)
{
    _x_texture = new_x;
    _y_texture = new_y;

    return *this;
}

} //namespace GL


