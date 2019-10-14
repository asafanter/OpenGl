#ifndef VBO_H
#define VBO_H

#include <vector>

#include "GL_types.h"
#include "Vertex.h"
#include "Attribute.h"

namespace GL {

class VBO
{
public:
    VBO();
    uint32 getID() const {return _id;}
    const std::vector<Attribute> getAttributes() const {return _attributes;}
    VBO &setVertices(const std::vector<Vertex> &new_vertices);
    VBO &addAttribute(const Attribute &atr);
    std::vector<Vertex> getVertices() const {return _vertices;}
    ~VBO();

private:
    uint32 _id;
    std::vector<Vertex> _vertices;
    std::vector<Attribute> _attributes;
};

} //namespace GL



#endif // VBO_H
