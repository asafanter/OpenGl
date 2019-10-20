#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>

#include "GL_types.h"

namespace GL {

class Texture
{
public:

    enum class Wrapping
    {
        REPEAT,
        MIRRORED_REPEAT,
        CLAMP_TO_EDGE,
        CLAMP_TO_BORDER
    };

    enum class Filtering
    {
        NEAREST,
        LINEAR
    };

    Texture();
    uint32 getID() const {return _id;}
    Wrapping getWrapping() const {return _wrapping;}
    Texture &setWrapping(const Texture::Wrapping &new_wrapping);
    Filtering getFiltering() const {return _filtering;}
    Texture &setFiltering(const Texture::Filtering &new_filtering);
    Texture &setImage(const string &image_file_name);
    bool isEmpty() const {return _data == nullptr;}

private: //methods
    const Texture &bind() const;
    const Texture &unbind() const;

private: //members
    uint32 _id;
    Wrapping _wrapping;
    Filtering _filtering;
    string _image_file_name;
    uint16 _width;
    uint16 _height;
    uint16 _num_of_components;
    uint8 *_data;
    std::vector<real32> _coords;
};

} //namespace GL



#endif // TEXTURE_H
