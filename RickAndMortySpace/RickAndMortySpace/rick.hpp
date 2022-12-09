//
//  rick.hpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#ifndef rick_hpp
#define rick_hpp

#include <stdio.h>
#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>

class Rick {
    sf::Texture rickTex;
    sf::Sprite rick;
    int hp = 10;
    sf::RectangleShape hpBar;

public:
    //Shooting variables
    std::vector<sf::RectangleShape> projectiles;
    sf::RectangleShape projectile;
    int shootTimer = 0;
    float coolTime = 0;
    
    //coolBar
    float cooldown = 10;
    sf::RectangleShape coolBar;
    Rick();
    void upDateRick(sf::RenderWindow& window);
    int getHp() { return hp; }
    void minusHp();
    void plusHp();
    sf::Sprite getRick();
    sf::RectangleShape getHpBar();
   
};


#endif /* rick_hpp */
