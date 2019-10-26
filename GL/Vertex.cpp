#include "Vertex.h"

namespace GL {

Vertex::Vertex(const real64 &x, const real64 &y, const real64 &z) :
    _x(REAL32(x)),
    _y(REAL32(y)),
    _z(REAL32(z))
{

}

Vertex &Vertex::setCoords(const real64 &new_x, const real64 &new_y, const real64 &new_z)
{
    _x = REAL32(new_x);
    _y = REAL32(new_y);
    _z = REAL32(new_z);

    return *this;
}

} //namespace GL


