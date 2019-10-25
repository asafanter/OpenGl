#ifndef COLOREDBUFFER_H
#define COLOREDBUFFER_H

#include <vector>

#include "ColoredVertex.h"
#include "Buffer.h"

namespace GL {

class ColoredBuffer : public Buffer
{
public:
    ColoredBuffer();
    ColoredBuffer &addVertex(const ColoredVertex &vertex) {_vertices.emplace_back(vertex); return *this;}
    ColoredBuffer &setVertices(const std::vector<ColoredVertex> &new_vertices) {_vertices = new_vertices; return *this;}
    virtual void setupVertices() const;
    virtual void setupAttributes() const;
    virtual uint32 getNumOfVertices() const {return UINT32(_vertices.size());}

private:
    std::vector<ColoredVertex> _vertices;
};


} //namespace GL


#endif // COLOREDBUFFER_H
