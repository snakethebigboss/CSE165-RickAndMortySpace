//
//  game.cpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#include "game.hpp"
#include<iostream>
#include <SFML/Graphics.hpp>
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<cstdlib>



// play game ()
Game::Game ()
{
    if (!texture.loadFromFile(resourcePath() + "rpjCi.jpg"))
    {
        std::cout << "could not load image" << std::endl;
    }
    background.setTexture(texture);
    
}

void Game::play(sf::Event& event, sf::RenderWindow& window, Menu& menu)
{
    if (menuSelected == 0)
    {
        window.clear();
        menu.draw(window);
        window.display();
    }
    if (menuSelected == 1) {
        window.clear();
        draw(window);
        collision();
        upDate(window);
    }
    if (rick.getHp() <= 0 || menuSelected == 2 )
    {
        reStart();
        endScreen(event, window);
    }
}

void Game::upDate(sf::RenderWindow& window)
{
    soda.upDateSoda(window);
    as.upDateAst(window);
    sat.upDateSat(window);
    tv.upDateTv(window);
    rick.upDateRick(window);
}

// if doge hits a cat
void Game::collision()
{
    for (size_t i = 0; i < tv.tvs.size(); i++)
    {
        if(rick.getRick().getGlobalBounds().intersects(tv.tvs[i].getGlobalBounds()))
        {
            rick.minusHp();
            tv.tvs.erase(tv.tvs.begin() + i);
        }
    }

    for (size_t i = 0; i< rick.projectiles.size(); i++) {
               for (size_t k = 0; k < tv.tvs.size(); k++) {
                   if(rick.projectiles[i].getGlobalBounds().intersects(tv.tvs[k].getGlobalBounds())) {
                       rick.projectiles.erase(rick.projectiles.begin() + i);
                       tv.tvs.erase(tv.tvs.begin() + k);
                       break;
                   }
               }
           }
    
    for (size_t i = 0; i < as.ats.size(); i++)
    {
        if(rick.getRick().getGlobalBounds().intersects(as.ats[i].getGlobalBounds()))
        {
            rick.minusHp();
            as.ats.erase(as.ats.begin() + i);
        }
    }

    for (size_t i = 0; i< rick.projectiles.size(); i++) {
               for (size_t k = 0; k < as.ats.size(); k++) {
                   if(rick.projectiles[i].getGlobalBounds().intersects(as.ats[k].getGlobalBounds())) {
                       rick.projectiles.erase(rick.projectiles.begin() + i);
                       as.ats.erase(as.ats.begin() + k);
                       break;
                   }
               }
           }
    for (size_t i = 0; i < sat.sats.size(); i++)
    {
        if(rick.getRick().getGlobalBounds().intersects(sat.sats[i].getGlobalBounds()))
        {
            rick.minusHp();
            sat.sats.erase(sat.sats.begin() + i);
        }
    }

    for (size_t i = 0; i< rick.projectiles.size(); i++) {
               for (size_t k = 0; k < sat.sats.size(); k++) {
                   if(rick.projectiles[i].getGlobalBounds().intersects(sat.sats[k].getGlobalBounds())) {
                       rick.projectiles.erase(rick.projectiles.begin() + i);
                       sat.sats.erase(sat.sats.begin() + k);
                       break;
                   }
               }
           }
    for (size_t i = 0; i < soda.sodas.size(); i++)
    {
        if(rick.getRick().getGlobalBounds().intersects(soda.sodas[i].getGlobalBounds()))
        {
            if (rick.getHp() < 10) {
                rick.plusHp();
            }
            soda.sodas.erase(soda.sodas.begin() + i);
        }
    }

    for (size_t i = 0; i< rick.projectiles.size(); i++) {
               for (size_t k = 0; k < soda.sodas.size(); k++) {
                   if(rick.projectiles[i].getGlobalBounds().intersects(soda.sodas[k].getGlobalBounds())) {
                       rick.projectiles.erase(rick.projectiles.begin() + i);
                       soda.sodas.erase(soda.sodas.begin() + k);
                       break;
                   }
               }
           }

    
    

    
    
}

// Draw the game
void Game::draw(sf::RenderWindow& window)
{
    window.clear();
    
    window.draw(background);
    
    window.draw(rick.getRick());

    for (size_t i = 0; i < tv.tvs.size(); i++)
    {
        window.draw(tv.tvs[i]);
    }
    for (size_t i = 0; i < as.ats.size(); i++)
    {
        window.draw(as.ats[i]);
    }
    for (size_t i = 0; i < sat.sats.size(); i++)
    {
        window.draw(sat.sats[i]);
    }
    for (size_t i = 0; i < soda.sodas.size(); i++)
    {
        window.draw(soda.sodas[i]);
    }
    window.draw(rick.getHpBar());
    
    for (size_t i = 0; i < rick.projectiles.size(); i++)
    {
        window.draw(rick.projectiles[i]);
    }
    window.draw(rick.coolBar);

    window.display();
}


//Add menu Screen
void Game::menuScreen(Menu& menu, sf::Event& event, sf::RenderWindow& window)
{
    if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::Return)
        {
            if (menu.GetPressItem() == 0)
            {
                std::cout <<"Play button has been pressed" << std::endl;
                menuSelected = 1;
                window.clear();
                
            }
        }
    }
}

void Game::endScreen(sf::Event& event, sf::RenderWindow& window)
{
    EndScreen endScreen(window.getSize().x, window.getSize().y);
    menuSelected = 2;
    window.clear();
    endScreen.draw(window);
    window.display();
    endEnter(endScreen, event, window);
}

void Game::endEnter(EndScreen& endScreen, sf::Event& event, sf::RenderWindow& window)
{
    if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::Return)
        {
            if (endScreen.GetPressItem() == 0)
            {
                std::cout <<"Restart button has been pressed" << std::endl;
                menuSelected = 1;
                window.clear();
                
            }
        }
    }
}

void Game::reStart()
{
    rick.restartHp();
    rick.cooldown = 10;
    sat.reStart();
    tv.reStart();
    as.reStart();
    soda.reStart();
}
