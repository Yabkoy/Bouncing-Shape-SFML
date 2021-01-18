#include <iostream>
#include <SFML/Graphics.hpp>

const int win_H = 600;
const int win_W = 800;

int main()
{
    sf::RenderWindow RW(sf::VideoMode(win_W, win_H), "Collision Detection");

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

        RW.display();
    }

    return 0;
}
