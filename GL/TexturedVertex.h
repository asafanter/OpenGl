#ifndef TEXTUREDVERTEX_H
#define TEXTUREDVERTEX_H

#include "GL_types.h"
#include "ColoredVertex.h"

namespace GL {

class TexturedVertex : public Vertex
{
public:
    TexturedVertex(const real64 &x = 0.0, const real64 &y = 0.0, const real64 &z = 0.0,
                   const real64 &x_texture = 0.0, const real64 &y_texture = 0.0);
    Vertex &setTextureCoords(const real64 &new_x, const real64 &new_y);
    real32 getXTexture() const {return _x_texture;}
    real32 getYTexture() const {return _y_texture;}

private:
    real32 _x_texture;
    real32 _y_texture;
};

} //namespace GL



#endif // TEXTUREDVERTEX_H
