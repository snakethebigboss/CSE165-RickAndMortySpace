//
//  game.hpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>


#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>
#include "opps.hpp"
#include "rick.hpp"
#include "MainMenu.hpp"

class Game{
public:
    Soda soda;
    Sat sat;
    Asteriod as;
    Rick rick;
    Tv tv;
    sf::Texture texture;
    sf::Sprite background;
    //Menu
    int menuSelected = 0;
    Game();
    void play(sf::RenderWindow& window, Menu& menu);
    void upDate(sf::RenderWindow& window);
    void collision();
    void draw(sf::RenderWindow& window);
    //Add menu
    void menuScreen(Menu& menu, sf::Event& event, sf::RenderWindow& window);
};




#endif /* game_hpp */
