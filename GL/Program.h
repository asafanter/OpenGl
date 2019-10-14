#ifndef PROGRAM_H
#define PROGRAM_H

#include "GL_types.h"
#include "Shader.h"

namespace GL {

class Program
{
public:
    Program();
    Program &attachShader(const Shader &shader);
    uint32 getID() const {return _id;}

private:
    uint32 _id;
};

} //namespace GL



#endif // PROGRAM_H
