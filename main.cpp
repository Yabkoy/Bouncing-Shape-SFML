#include "windowFrame.h"

const int win_H = 600;
const int win_W = 800;

const float mainSpeed = 0.1;

float movingX = mainSpeed;
float movingY = mainSpeed;

int main()
{
    sf::RenderWindow RW(sf::VideoMode(win_W, win_H), "Collision Detection", sf::Style::Default);

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
        }
        RW.clear(sf::Color::Black);

        for(int i=0; i<wF.getFrameSize(); i++)
        {
            RW.draw(wF.getFrameElement(i));
        }

        if(RS.getGlobalBounds().intersects(wF.getFrameElement(1).getGlobalBounds()) || RS.getGlobalBounds().intersects(wF.getFrameElement(3).getGlobalBounds()))
            movingY = -movingY;
        if(RS.getGlobalBounds().intersects(wF.getFrameElement(0).getGlobalBounds()) || RS.getGlobalBounds().intersects(wF.getFrameElement(2).getGlobalBounds()))
            movingX = -movingX;

        RS.move(sf::Vector2f(movingX, movingY));

        RW.draw(RS);

        RW.display();
    }

    return 0;
}
