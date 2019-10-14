#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace GL {

using string = std::string;
using uint = unsigned int;

class Shader
{
public:
    Shader& setSource(const string& src);
    Shader& compile();
    uint getId() const {return _id;}

protected:
    uint _id;
};
}

#endif // SHADER_H
