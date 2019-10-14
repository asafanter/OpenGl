#ifndef SHADER_H
#define SHADER_H

#include "GL_types.h"

namespace GL {

class Shader
{
public:
    Shader();
    Shader &setSource(const string &file_name);
    uint32 getID() const {return _id;}
    string getSource() const {return _src;}
    ~Shader();

protected:
    uint32 _id;
    string _src;
};

} //namespace GL



#endif // SHADER_H
