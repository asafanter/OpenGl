#ifndef VERTEX_H
#define VERTEX_H

#include "GL_types.h"

namespace GL {

class Vertex
{
public:
    Vertex(const real64 &x = 0.0, const real64 &y = 0.0, const real64 &z = 0.0);
    Vertex &setCoords(const real64 &new_x, const real64 &new_y, const real64 &new_z);
    Vertex &setX(const real64 &new_x) {_x = REAL32(new_x); return *this;}
    Vertex &setY(const real64 &new_y) {_y = REAL32(new_y); return *this;}
    Vertex &setZ(const real64 &new_z) {_z = REAL32(new_z); return *this;}
    real32 getX() const {return _x;}
    real32 getY() const {return _y;}
    real32 getZ() const {return _z;}

private:
    real32 _x;
    real32 _y;
    real32 _z;
};

} //namespace GL


#endif // VERTEX_H
