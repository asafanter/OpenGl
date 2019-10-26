#include <iostream>

#include "Color.h"

namespace GL {

Color::Color(const uint32 &r, const uint32 &g, const uint32 &b, const uint32 &a) :
    _r(r / 255.0f),
    _g(g / 255.0f),
    _b(b / 255.0f),
    _a(a / 255.0f)
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
        _r = 0.0f;
        _g = 0.0f;
        _b = 0.0f;
        _a = 1.0f;
    }
    else if(dye == Color::Dye::WHITE)
    {
        _r = 1.0f;
        _g = 1.0f;
        _b = 1.0f;
        _a = 1.0f;
    }
    else if(dye == Color::Dye::RED)
    {
        _r = 1.0f;
        _g = 0.0f;
        _b = 0.0f;
        _a = 1.0f;
    }
    else if(dye == Color::Dye::GREEN)
    {
        _r = 0.0f;
        _g = 1.0f;
        _b = 0.0f;
        _a = 1.0f;
    }
    else if(dye == Color::Dye::BLUE)
    {
        _r = 0.0f;
        _g = 0.0f;
        _b = 1.0f;
        _a = 1.0f;
    }
    else if(dye == Color::Dye::YELLOW)
    {
        _r = 1.0f;
        _g = 1.0f;
        _b = 0.0f;
        _a = 1.0f;
    }
}

Color &Color::setRed(const uint32 &new_red)
{
    _r = new_red / 255.0f;
    validAndLimitComponent(_r);

    return *this;
}

Color &Color::setGreen(const uint32 &new_green)
{
    _g = new_green / 255.0f;
    validAndLimitComponent(_g);

    return *this;
}

Color &Color::setBlue(const uint32 &new_blue)
{
    _b = new_blue / 255.0f;
    validAndLimitComponent(_b);

    return *this;
}

Color &Color::setAlpha(const uint32 &new_alpha)
{
    _a = new_alpha / 255.0f;
    validAndLimitComponent(_a);

    return *this;
}

Color &Color::validAndLimitComponent(float &component)
{
    if(component < 0.0f || component > 1.0f)
    {
        std::cerr << "Color warning: color component limit be between 0 to 255" << std::endl;
    }

    if(component < 0.0f)
    {
        component = 0.0f;
    }

    if(component > 1.0f)
    {
        component = 1.0f;
    }

    return *this;
}


} //namespace GL


