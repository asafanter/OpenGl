#ifndef VERTEX_H
#define VERTEX_H

#include "GL_types.h"
#include "Color.h"

namespace GL {

class Vertex
{
public:
    Vertex(const real32 &x = 0.0, const real32 &y = 0.0, const real32 &z = 0.0,
           const Color &color = Color(Color::BLUE), const uint32 size = 3);
    Vertex &setColor(const Color &new_color);
    Vertex &setSize(const uint32 &new_size);
    Vertex &setCoords(const real32 &new_x, const real32 &new_y, const real32 &new_z);
    Vertex &setX(const real32 &new_x);
    Vertex &setY(const real32 &new_y);
    Vertex &setZ(const real32 &new_z);
    real32 getX() const {return _x;}
    real32 getY() const {return _y;}
    real32 getZ() const {return _z;}
    uint32 getSize() const {return _size;}
    Color getColor() const {return _color;}

private:
    real32 _x;
    real32 _y;
    real32 _z;
    Color _color;
    uint32 _size;
};

} //namespace GL



#endif // VERTEX_H
