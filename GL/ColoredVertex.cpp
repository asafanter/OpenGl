#include "ColoredVertex.h"

namespace GL {

ColoredVertex::ColoredVertex(const real64 &x, const real64 &y, const real64 &z, const Color &color) :
    Vertex(x, y, z),
    _color(color)
{

}

} //namespace GL


