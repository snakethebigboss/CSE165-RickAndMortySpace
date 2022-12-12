//
//  endScreen.cpp
//  RickAndMortySpace
//
//  Created by Natalie Diaz on 12/11/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#include "endScreen.hpp"


EndScreen::EndScreen(float width, float height)
{
    if (!font.loadFromFile(resourcePath() + "ChrustyRock-ORLA.ttf"))
    {
        std::cout << "failed to load font";
    }
    
    end[0].setFont(font);
    end[0].setFillColor(sf::Color::Green);
    end[0].setString("Press enter to restart");
    end[0].setCharacterSize(60);
    end[0].setPosition(sf::Vector2f(width / 5.5, height / 3));
    
    
    
    selectedItemsIndex = 0;
    
    if (!texture.loadFromFile(resourcePath() + "rpJCi.jpg"))
    {
        std::cout << "failed to load image";
    }
    
    background.setTexture(texture);
    
}

void EndScreen::draw(sf::RenderWindow &window)
{
    window.draw(background);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(end[i]);
    }
}


