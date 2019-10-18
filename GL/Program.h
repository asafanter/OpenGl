#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

#include "GL_types.h"
#include "Shader.h"

namespace GL {

class Program
{
public:
    Program();
    Program &attachShader(const Shader &shader);
    uint32 getID() const {return _id;}
    bool hasShadersAttached() const {return _shaders_attached.size() > 0;}

private:
    uint32 _id;
    std::vector<uint32> _shaders_attached;
};

} //namespace GL



#endif // PROGRAM_H
