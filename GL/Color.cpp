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

Color::Color(const float &r, const float &g, const float &b, const float &a) :
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

Color &Color::setRed(const float &new_red)
{
    _r = new_red;
    validAndLimitComponent(_r);

    return *this;
}

Color &Color::setGreen(const float &new_green)
{
    _g = new_green;
    validAndLimitComponent(_g);

    return *this;
}

Color &Color::setBlue(const float &new_blue)
{
    _b = new_blue;
    validAndLimitComponent(_b);

    return *this;
}

Color &Color::setAlpha(const float &new_alpha)
{
    _a = new_alpha;
    validAndLimitComponent(_a);

    return *this;
}

Color &Color::validAndLimitComponent(float &component)
{
    if(component < 0.0f || component > 1.0f)
    {
        std::cerr << "Color warning: color component limit be between 0.0 to 1.0" << std::endl;
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


