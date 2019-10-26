#ifndef COLORED_VERTEX_H
#define COLORED_VERTEX_H

#include "GL_types.h"
#include "Vertex.h"
#include "Color.h"

namespace GL {

class ColoredVertex : public Vertex
{
public:
    ColoredVertex(const real64 &x = 0.0, const real64 &y = 0.0, const real64 &z = 0.0,
           const Color &color = Color(Color::BLUE));
    ColoredVertex &setColor(const Color &new_color) {_color = new_color; return *this;}
    Color getColor() const {return _color;}

protected:
    Color _color;
};

} //namespace GL



#endif // COLORED_VERTEX_H
