//
//  MainMenu.hpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>

#define MAX_NUMBER_OF_ITEMS 1

class Menu
{
    int selectedItemsIndex;
    sf::Texture texture;
    sf::Sprite background;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    
public:
    Menu(float width, float height);
    ~Menu();
    
    void draw(sf::RenderWindow &window);
    int GetPressItem() {return selectedItemsIndex;}
};

#endif
