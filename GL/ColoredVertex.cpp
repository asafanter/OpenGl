#include "ColoredVertex.h"

namespace GL {

ColoredVertex::ColoredVertex(const real32 &x, const real32 &y, const real32 &z, const Color &color) :
    Vertex(x, y, z),
    _color(color)
{

}

} //namespace GL


