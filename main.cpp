#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

const int win_H = 600;
const int win_W = 800;

class windowFrame
{
private:
    int mainH;
    int mainW;
    std::array<sf::RectangleShape, 4> mainFrames;
public:
    windowFrame(const int& w, const int& h) : mainW(w), mainH(h) {}

    void init()
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
    int getFrameSize() const
    {
        return mainFrames.size();
    }

    void setFrameColor(const sf::Color& myColor)
    {
        for(int i=0; i<mainFrames.size(); i++)
        {
            mainFrames[i].setFillColor(myColor);
        }
    }
    void checkColisionDetection(const sf::RectangleShape& mainS)
    {
        for(int i=0; i<mainFrames.size(); i++)
        {
            if(mainS.getGlobalBounds().intersects(mainFrames[i].getGlobalBounds()))
            {std::cout<<i<<std::endl;}
        }

    }

    sf::RectangleShape getFrameElement(const int& numberOfArray) const
    {
        return mainFrames[numberOfArray];
    }

};

int main()
{
    sf::RenderWindow RW(sf::VideoMode(win_W, win_H), "Collision Detection");

    windowFrame wF(win_W, win_H);

    wF.init();
    wF.setFrameColor(sf::Color::Red);

    sf::RectangleShape RS(sf::Vector2f(100, 100));
    RS.setFillColor(sf::Color::Green);

    while(RW.isOpen())
    {
        sf::Event mainEvent;
        if(RW.pollEvent(mainEvent))
        {
            if(mainEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                RW.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                RS.move(sf::Vector2f(0, -10));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                RS.move(sf::Vector2f(0, 10));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                RS.move(sf::Vector2f(-10, 0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                RS.move(sf::Vector2f(10, 0));
            }
        }
        RW.clear(sf::Color::Black);

        for(int i=0; i<wF.getFrameSize(); i++)
        {
            RW.draw(wF.getFrameElement(i));
        }
        RW.draw(RS);

        wF.checkColisionDetection(RS);

        RW.display();
    }

    return 0;
}
