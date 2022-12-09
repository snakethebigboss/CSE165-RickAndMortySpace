//
//  rick.cpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#include "rick.hpp"
#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>
#include "ResourcePath.hpp"



Rick::Rick () {
    if (!rickTex.loadFromFile(resourcePath() + "rick.png"))
    {
        throw "Could not load image!";
    }
        
    rick.setTexture(rickTex);
    rick.setScale(sf::Vector2f(0.3f,0.3f));
    hpBar.setFillColor(sf::Color::Green);
    hpBar.setSize(sf::Vector2f((float)hp * 20.f, 20.f));
    hpBar.setPosition(500 - hpBar.getGlobalBounds().width/2, 0);
    
    //Shooting variables
    projectile.setSize(sf::Vector2f(30.f,12.f));
    projectiles.push_back(sf::RectangleShape(projectile));
    projectile.setFillColor(sf::Color::Red);
    
    //coolBar
    coolBar.setFillColor(sf::Color::Red);
    coolBar.setSize(sf::Vector2f(cooldown * 20.f, 20.f));
    coolBar.setPosition(500 - coolBar.getGlobalBounds().width/2, 780 - coolBar.getGlobalBounds().height);

}

//UPDATE
//DoGE (Player)
void Rick::upDateRick(sf::RenderWindow& window) {
    rick.setPosition(rick.getPosition().x, sf::Mouse::getPosition(window).y);
    if(rick.getPosition().y > window.getSize().y - rick.getGlobalBounds().height)
    {
        rick.setPosition(rick.getPosition().x, window.getSize().y - rick.getGlobalBounds().height);
    }
    
    if(rick.getPosition().y < 0)
    {
        rick.setPosition(rick.getPosition().x, 0);
    }
    //UI
    hpBar.setSize(sf::Vector2f(20.f * (float)hp, 20.f));
    
    //shooting

    if (shootTimer < 5)
    {
        shootTimer++;
    }


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& shootTimer >= 5 && coolTime < 25)
    {
        projectile.setPosition(rick.getPosition().x + rick.getGlobalBounds().width, rick.getPosition().y + rick.getGlobalBounds().height/2);
        projectiles.push_back(sf::RectangleShape(projectile));
        shootTimer = 0;
        coolTime++;
        cooldown = 10 - (coolTime/25) *  10;
    }

    if(coolTime >= 25)
    {
        coolTime++;
        cooldown = 0 + (coolTime/1000) *  10;
    }



    if(coolTime == 1000)
    {
        coolTime = 0;
    }

    for (size_t i = 0; i< projectiles.size(); i++) {
        projectiles[i].move(10.f,0.f);

        if(projectiles[i].getPosition().y <= 0){
            projectiles.erase(projectiles.begin()+i);
        }
    }
    
    //UI
    coolBar.setSize(sf::Vector2f(cooldown * 20.f,20.f));
    
    for (size_t i = 0; i < projectiles.size(); i++)
    {
                window.draw(projectiles[i]);
    }
    
}
   

// minus one from hp
void Rick::minusHp()
{
    hp--;
}
void Rick::plusHp()
{
    hp++;
}

sf::Sprite Rick::getRick()
{
    return rick;
}

sf::RectangleShape Rick::getHpBar()
{
    return hpBar;
}



