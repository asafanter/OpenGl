#ifndef COLOR_H
#define COLOR_H

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

    Color();
    Color(const float &r, const float& g, const float &b, const float &a);
    Color(const Color::Dye &dye);
    Color &setRed(const float &new_red);
    Color &setGreen(const float &new_green);
    Color &setBlue(const float &new_blue);
    Color &setAlpha(const float &new_alpha);
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
