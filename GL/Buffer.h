#ifndef BUFFER_H
#define BUFFER_H

namespace GL {

class Buffer
{
public:
    virtual void setupVertices() const = 0;
    virtual void setupAttributes() const = 0;
    virtual ~Buffer() = default;
};

} //namespace GL



#endif // BUFFER_H
