#ifndef VAO_H
#define VAO_H

#include <vector>

#include "GL_types.h"
#include "Attribute.h"
#include <Vertex.h>

namespace GL {

class VAO
{
public:

    VAO();
    uint32 getID() const {return _id;}
    VAO &setPremitive(const GL::Premitive &new_premitive) {_premitive = new_premitive; return *this;}
    VAO &setVertices(const std::vector<Vertex> &new_vertices);
    VAO &addAttribute(const Attribute &atr);
    bool hasVertices() const {return _vertices.size() > 0;}
    bool hasAttributes() const {return _attributes.size() > 0;}
    void remove();
    uint64 getNumOfVertices() const {return _vertices.size();}
    Premitive getPremitive() const {return _premitive;}

private: //defs
    struct VBO
    {
        uint32 id;
    };

private: //methods
    const VAO &bind() const;
    const VAO &unbind() const;

private: //members
    uint32 _id;
    Premitive _premitive;
    VBO _vbo;
    std::vector<Vertex> _vertices;
    std::vector<Attribute> _attributes;
};

} //namespace GL



#endif // VAO_H
