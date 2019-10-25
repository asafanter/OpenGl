#include "Vertex.h"

namespace GL {

Vertex::Vertex(const real32 &x, const real32 &y, const real32 &z) :
    _x(x),
    _y(y),
    _z(z)
{

}

Vertex &Vertex::setCoords(const real32 &new_x, const real32 &new_y, const real32 &new_z)
{
    _x = new_x;
    _y = new_y;
    _z = new_z;

    return *this;
}

} //namespace GL


