
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>


#include "opps.hpp"
#include "rick.hpp"
#include "game.hpp"
#include "MainMenu.hpp"


using namespace sf;

int main()
{
    sf::RenderWindow window(VideoMode(1000, 780), "Run");
    window.setFramerateLimit(60);
    Game Start;
    //Added menu
    Menu menu(window.getSize().x, window.getSize().y);
    
    //GAME LOOP
    
    while (window.isOpen() && Start.rick.getHp() > 0)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                window.close();
            }
            Start.menuScreen(menu, event, window);
        }
    
        
        Start.play(window, menu);
    }

     
    
    return 0;
}
