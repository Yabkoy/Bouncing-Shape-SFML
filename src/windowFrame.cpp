#include "windowFrame.h"

windowFrame::windowFrame(const int& w, const int& h) : mainW(w), mainH(h) {}

void windowFrame::init()
{
    for(int i=0; i<mainFrames.size(); i+=2)
    {
        mainFrames[i].setSize(sf::Vector2f(10, mainH));
        mainFrames[i+1].setSize(sf::Vector2f(mainW, 10));
    }
    mainFrames[0].setPosition(sf::Vector2f(-10, 0));
    mainFrames[1].setPosition(sf::Vector2f(0, -10));
    mainFrames[2].setPosition(sf::Vector2f(mainW, 0));
    mainFrames[3].setPosition(sf::Vector2f(0, mainH));
}

int windowFrame::getFrameSize() const
{
    return mainFrames.size();
}

void windowFrame::setFrameColor(const sf::Color& myColor)
{
    for(int i=0; i<mainFrames.size(); i++)
    {
        mainFrames[i].setFillColor(myColor);
    }
}

void windowFrame::checkColisionDetection(const sf::RectangleShape& mainS) const
{
    for(int i=0; i<mainFrames.size(); i++)
    {
        if(mainS.getGlobalBounds().intersects(mainFrames[i].getGlobalBounds()))
        {std::cout<<i<<std::endl;}
    }
}

sf::RectangleShape windowFrame::getFrameElement(const int& numberOfArray) const
{
    return mainFrames[numberOfArray];
}
