#ifndef VAO_H
#define VAO_H

#include <vector>
#include <memory>

#include "GL_types.h"
#include "VBO.h"

namespace GL {

class VAO
{
public:

    VAO();
    VAO &setVBO(const VBO &vbo);
    uint32 getID() const {return _id;}
    VAO &setPremitive(const GL::Premitive &new_premitive);
    Premitive getPremitive() const {return _premitive;}
    VBO getVBO() const {return *_vbo;}
    bool hasVBO() const {return _vbo != nullptr;}

private:
    uint32 _id;
    Premitive _premitive;
    std::shared_ptr<VBO> _vbo;
};

} //namespace GL



#endif // VAO_H
