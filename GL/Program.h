#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

#include "Shader.h"

namespace GL {

using uint = unsigned int;

class Program
{
public:
    Program();
    Program &addShader(const Shader &shader);
    Program &link();

private:
    uint _id;
};
}

#endif // PROGRAM_H
