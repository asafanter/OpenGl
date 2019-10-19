#ifndef SHADER_H
#define SHADER_H

#include "GL_types.h"

namespace GL {

class Shader
{
public:
    Shader();
    void remove();
    Shader &setSource(const string &file_name);
    const Shader &compile() const;
    uint32 getID() const {return _id;}
    string getSource() const {return _src;}
    bool isSourceSet() const {return !_src.empty();}
    virtual ~Shader();

protected:
    uint32 _id;
    string _src;
};

} //namespace GL



#endif // SHADER_H
