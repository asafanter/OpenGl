#include <glad/glad.h>
#include <iostream>

#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace GL {

Texture::Texture() :
    _id(UINT32(-1)),
    _wrapping(Wrapping::REPEAT),
    _filtering(Filtering::NEAREST),
    _image_file_name(),
    _width(0),
    _height(0),
    _num_of_components(0),
    _data(nullptr)
{
    glGenTextures(1, &_id);
}

const Texture &Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, _id);

    return *this;
}

const Texture &Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);

    return *this;
}

Texture &Texture::setWrapping(const Texture::Wrapping &new_wrapping)
{
    bind();

    if(new_wrapping == Wrapping::REPEAT)
    {
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    else if(new_wrapping == Wrapping::MIRRORED_REPEAT)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    }
    else if(new_wrapping == Wrapping::CLAMP_TO_EDGE)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else if(new_wrapping == Wrapping::CLAMP_TO_BORDER)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    }

    unbind();

    return *this;
}

Texture &Texture::setFiltering(const Filtering &new_filtering)
{
    bind();

    if(new_filtering == Filtering::NEAREST)
    {
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    else if(new_filtering == Filtering::LINEAR)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    unbind();

    return *this;
}

Texture &Texture::setImage(const string &image_file_name)
{
    if(image_file_name.empty())
    {
        std::cerr << "image file name is empty" << std::endl;
        return *this;
    }

    int width = 0;
    int height = 0;
    int num_of_components = 0;

    bind();

    stbi_set_flip_vertically_on_load(true);
    _data = stbi_load(image_file_name.c_str(), &width, &height, &num_of_components, 0);

    _width = UINT16(width);
    _height = UINT16(height);
    _num_of_components = UINT16(num_of_components);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(_data);

    unbind();

    return *this;
}

} //namespace GL

