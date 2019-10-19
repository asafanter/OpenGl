#include "Vertex.h"

namespace GL {

Vertex::Vertex(const real32 &x, const real32 &y, const real32 &z, const Color &color) :
    _x(x),
    _y(y),
    _z(z),
    _color(color),
    _x_texture(0.0),
    _y_texture(0.0)
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


