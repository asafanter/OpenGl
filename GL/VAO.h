#ifndef VAO_H
#define VAO_H

#include <vector>

#include "GL_types.h"

namespace GL {

class VAO
{
public:

    enum class Premitive
    {
        POINTS,
        LINES,
        TRIANGLES
    };

    VAO();
    uint32 getID() const {return _id;}
    VAO &setPremitive(const Premitive &new_premitive);
    Premitive getPremitive() const {return _premitive;}

private:
    uint32 _id;
    Premitive _premitive;
};

} //namespace GL



#endif // VAO_H
