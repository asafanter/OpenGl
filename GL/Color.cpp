#include <iostream>

#include "Color.h"

namespace GL {

Color::Color() :
    _r(0.0),
    _g(0.0),
    _b(0.0),
    _a(1.0)
{

}

Color::Color(const uint32 &r, const uint32 &g, const uint32 &b, const uint32 &a) :
    _r(r),
    _g(g),
    _b(b),
    _a(a)
{
    validAndLimitComponent(_r);
    validAndLimitComponent(_g);
    validAndLimitComponent(_b);
    validAndLimitComponent(_a);
}

Color::Color(const Color::Dye &dye)
{
    if(dye == Color::Dye::BLACK)
    {
        _r = 0;
        _g = 0;
        _b = 0;
        _a = 255;
    }
    else if(dye == Color::Dye::WHITE)
    {
        _r = 255;
        _g = 255;
        _b = 255;
        _a = 255;
    }
    else if(dye == Color::Dye::RED)
    {
        _r = 255;
        _g = 0;
        _b = 0;
        _a = 255;
    }
    else if(dye == Color::Dye::GREEN)
    {
        _r = 0;
        _g = 255;
        _b = 0;
        _a = 255;
    }
    else if(dye == Color::Dye::BLUE)
    {
        _r = 0;
        _g = 0;
        _b = 255;
        _a = 255;
    }
    else if(dye == Color::Dye::YELLOW)
    {
        _r = 255;
        _g = 255;
        _b = 0;
        _a = 255;
    }
}

Color &Color::setRed(const uint32 &new_red)
{
    _r = new_red;
    validAndLimitComponent(_r);

    return *this;
}

Color &Color::setGreen(const uint32 &new_green)
{
    _g = new_green;
    validAndLimitComponent(_g);

    return *this;
}

Color &Color::setBlue(const uint32 &new_blue)
{
    _b = new_blue;
    validAndLimitComponent(_b);

    return *this;
}

Color &Color::setAlpha(const uint32 &new_alpha)
{
    _a = new_alpha;
    validAndLimitComponent(_a);

    return *this;
}

Color &Color::validAndLimitComponent(uint32 &component)
{
    if(component > 255)
    {
        std::cerr << "Color warning: color component limit be between 0 to 255" << std::endl;
    }

    if(component > 255)
    {
        component = 255;
    }

    return *this;
}


} //namespace GL


