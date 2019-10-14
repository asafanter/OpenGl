#include "Vertex.h"

namespace GL {

Vertex::Vertex(const real32 &x, const real32 &y, const real32 &z, const Color &color, const uint32 size) :
    _x(x),
    _y(y),
    _z(z),
    _color(color),
    _size(size)
{

}

Vertex &Vertex::setColor(const Color &new_color)
{
    _color = new_color;

    return *this;
}

Vertex &Vertex::setSize(const uint32 &new_size)
{
    _size = new_size;

    return *this;
}

Vertex &Vertex::setCoords(const real32 &new_x, const real32 &new_y, const real32 &new_z)
{
    _x = new_x;
    _y = new_y;
    _z = new_z;

    return *this;
}

Vertex &Vertex::setX(const real32 &new_x)
{
    _x = new_x;

    return *this;
}

Vertex &Vertex::setY(const real32 &new_y)
{
    _y = new_y;

    return *this;
}

Vertex &Vertex::setZ(const real32 &new_z)
{
    _z = new_z;

    return *this;
}

} //namespace GL


