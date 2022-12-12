//
//  MainMenu.cpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#include "MainMenu.hpp"
#include "ResourcePath.hpp"


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile(resourcePath() + "ChrustyRock-ORLA.ttf"))
    {
        std::cout << "failed to load font";
    }
    
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("ENTER");
    menu[0].setCharacterSize(150);
    menu[0].setPosition(sf::Vector2f(width /4, height /2));
    
    
    
    selectedItemsIndex = 0;
    
    if (!texture.loadFromFile(resourcePath() + "rm.png"))
    {
        std::cout << "failed to load image";
    }
    
    background.setTexture(texture);
    

    
}

Menu::~Menu()
{
    
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(background);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

