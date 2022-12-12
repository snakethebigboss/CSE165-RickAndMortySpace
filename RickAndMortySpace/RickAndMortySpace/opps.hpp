//
//  opps.hpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#ifndef opps_hpp
#define opps_hpp


#include <stdio.h>
#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>
#include "ResourcePath.hpp"

 
class Tv {
    sf::Texture tvTex;
    sf::Sprite tv;
    int tvSpawnTimer = 15;
public:
    Tv();
    std::vector<sf::Sprite> tvs;
    void upDateTv(sf::RenderWindow& window);
    void reStart();

};
class Asteriod{
    sf::Texture asTex;
    sf::Sprite as;
    int atSpawnTimer = 15;
public:
    Asteriod();
    std::vector<sf::Sprite> ats;
    void upDateAst(sf::RenderWindow& window);
    void reStart();

};
class Sat{
    sf::Texture satTex;
    sf::Sprite sat;
    int SatSpawnTimer = 15;
public:
    Sat();
    std::vector<sf::Sprite> sats;
    void upDateSat(sf::RenderWindow& window);
    void reStart();

};
class Soda{
    sf::Texture sodaTex;
    sf::Sprite soda;
    int SodaSpawnTimer = 15;
public:
    Soda();
    std::vector<sf::Sprite> sodas;
    void upDateSoda(sf::RenderWindow& window);
    void reStart ();

};


#endif /* opps_hpp */
