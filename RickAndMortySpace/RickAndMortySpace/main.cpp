
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
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <SFML/Audio.hpp>
#include<cstdlib>


#include "opps.hpp"
#include "rick.hpp"
#include "game.hpp"
#include "MainMenu.hpp"


using namespace sf;

int main()
{
    sf::RenderWindow window(VideoMode(1000, 780), "Rick And Morty: Space Adventure");
    window.setFramerateLimit(60);
    Game Start;
    //Added menu
    Menu menu(window.getSize().x, window.getSize().y);
    
    //GAME LOOP
   
    sf:: Music music;
    if (!music.openFromFile( "RickAndMortySpace/sound.ogg" )){
        std::cout<< "Error"<<std::endl;
    }

        music.play();
    
    while (window.isOpen())
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
            
            //endScreen

        }
    
        Start.play(event,window, menu);
        if(Start.rick.getHp() <= 0)
        {
            Start.endScreen(event, window);
        }
    }

     
    
    return 0;
}
