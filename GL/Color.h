#ifndef COLOR_H
#define COLOR_H

#include "GL_types.h"

namespace GL {

class Color
{
public:

    enum Dye
    {
        BLACK,
        WHITE,
        RED,
        GREEN,
        BLUE,
        YELLOW
    };

    Color(const uint32 &r = 0, const uint32& g = 0, const uint32 &b = 0, const uint32 &a = 255);
    Color(const Color::Dye &dye);
    Color &setRed(const uint32 &new_red);
    Color &setGreen(const uint32 &new_green);
    Color &setBlue(const uint32 &new_blue);
    Color &setAlpha(const uint32 &new_alpha);
    float getRed() const {return _r;}
    float getGreen() const {return _g;}
    float getBlue() const {return _b;}
    float getAlpha() const {return _a;}

private: //methods

    Color &validAndLimitComponent(float &component);

private: //members
    float _r;
    float _g;
    float _b;
    float _a;
};

} //namespace GL



#endif // COLOR_H
