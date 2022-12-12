//
//  endScreen.hpp
//  RickAndMortySpace
//
//  Created by Natalie Diaz on 12/11/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#ifndef endScreen_hpp
#define endScreen_hpp

#include <stdio.h>
#include <iostream>
#include "SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include "ResourcePath.hpp"
#include<cstdlib>


#define MAX_NUMBER_OF_ITEMS 1

class EndScreen
{
    int selectedItemsIndex;
    sf::Texture texture;
    sf::Sprite background;
    sf::Font font;
    sf::Text end[MAX_NUMBER_OF_ITEMS];
    
public:
    EndScreen(float width, float height);
    void draw(sf::RenderWindow &window);
    int GetPressItem() {return selectedItemsIndex;}
};

#endif /* endScreen_hpp */
