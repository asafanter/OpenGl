#ifndef VERTEX_H
#define VERTEX_H

#include "GL_types.h"
#include "Color.h"

namespace GL {

class Vertex
{
public:
    Vertex(const real32 &x = 0.0, const real32 &y = 0.0, const real32 &z = 0.0,
           const Color &color = Color(Color::BLUE), const real32 &x_texture = 0.0, const real32 &y_texture = 0.0);
    Vertex &setColor(const Color &new_color) {_color = new_color; return *this;}
    Vertex &setCoords(const real32 &new_x, const real32 &new_y, const real32 &new_z);
    Vertex &setTextureCoords(const real32 &new_x, const real32 &new_y);
    Vertex &setX(const real32 &new_x) {_x = new_x; return *this;}
    Vertex &setY(const real32 &new_y) {_y = new_y; return *this;}
    Vertex &setZ(const real32 &new_z) {_z = new_z; return *this;}
    real32 getX() const {return _x;}
    real32 getY() const {return _y;}
    real32 getZ() const {return _z;}
    Color getColor() const {return _color;}

private:
    real32 _x;
    real32 _y;
    real32 _z;
    Color _color;
    real32 _x_texture;
    real32 _y_texture;
};

} //namespace GL



#endif // VERTEX_H
