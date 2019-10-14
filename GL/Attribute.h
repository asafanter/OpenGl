#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "GL_types.h"

namespace GL {

class Attribute
{
public:
    Attribute(const uint32 &id, const uint32 &offset);
    uint32 getID() const {return _id;}
    uint32 offset() const {return _offset;}

private:
    uint32 _id;
    uint32 _offset;
};

} //namespace GL


#endif // ATTRIBUTE_H
