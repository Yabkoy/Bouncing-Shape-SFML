#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H

class windowFrame
{
private:
    int mainH;
    int mainW;
    std::array<sf::RectangleShape, 4> mainFrames;
public:
    windowFrame(const int& w, const int& h);

    void init();

    int getFrameSize() const;

    void setFrameColor(const sf::Color& myColor);

    void checkColisionDetection(const sf::RectangleShape& mainS) const;

    sf::RectangleShape getFrameElement(const int& numberOfArray) const;

};

#endif // WINDOWFRAME_H
