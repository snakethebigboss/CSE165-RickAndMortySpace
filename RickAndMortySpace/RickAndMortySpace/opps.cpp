//
//  opps.cpp
//  RickAndMortySpace
//
//  Created by Julian Grado on 12/4/22.
//  Copyright © 2022 Julian Grado. All rights reserved.
//

#include "opps.hpp"
Tv::Tv ()
{

    if (!tvTex.loadFromFile(resourcePath() + "tv.png"))
    {
        throw "Could not load bunny.png!";
    }

    tv.setTexture(tvTex);
    tv.setScale(sf::Vector2f(0.3f, 0.3f));
    tvs.push_back(sf::Sprite(tv));
}

//UPDATE
//CATS

void Tv::upDateTv(sf::RenderWindow& window) {

    for (size_t i = 0; i < tvs.size(); i++)
    {
        tvs[i].move(-7.f, 0.f);

        if(tvs[i].getPosition().x < 0 - tv.getGlobalBounds().width)
        {
            tvs.erase(tvs.begin() + i);
        }
    }

    if(tvSpawnTimer < 40)
    {
        tvSpawnTimer++;

    }

    if(tvSpawnTimer >= 40)
    {
        tv.setPosition(window.getSize().x, rand()%int(window.getSize().y - tv.getGlobalBounds().height));
        tvs.push_back(sf::Sprite(tv));
        tvSpawnTimer = 0;
    }
}

Asteriod::Asteriod()
{

    if (!asTex.loadFromFile(resourcePath()+ "rock.png"))
    {
        throw "Could not load bunny.png!";
    }

    as.setTexture(asTex);
    as.setScale(sf::Vector2f(0.3f, 0.3f));
    ats.push_back(sf::Sprite(as));
}

void Asteriod::upDateAst(sf::RenderWindow& window) {

    for (size_t i = 0; i < ats.size(); i++)
    {
        ats[i].move(-7.f, 0.f);

        if(ats[i].getPosition().x < 0 - as.getGlobalBounds().width)
        {
            ats.erase(ats.begin() + i);
        }
    }

    if(atSpawnTimer < 40)
    {
        atSpawnTimer++;

    }

    if(atSpawnTimer >= 40)
    {
        as.setPosition(window.getSize().x, rand()%int(window.getSize().y - as.getGlobalBounds().height));
        ats.push_back(sf::Sprite(as));
        atSpawnTimer = 0;
    }
}

Sat::Sat()
{

    if (!satTex.loadFromFile(resourcePath()+ "tele.png"))
    {
        throw "Could not load bunny.png!";
    }

    sat.setTexture(satTex);
    sat.setScale(sf::Vector2f(0.3f, 0.3f));
    sats.push_back(sf::Sprite(sat));
}

void Sat::upDateSat(sf::RenderWindow& window) {

    for (size_t i = 0; i < sats.size(); i++)
    {
        sats[i].move(-7.f, 0.f);

        if(sats[i].getPosition().x < 0 - sat.getGlobalBounds().width)
        {
            sats.erase(sats.begin() + i);
        }
    }

    if(SatSpawnTimer < 40)
    {
        SatSpawnTimer++;

    }

    if(SatSpawnTimer >= 40)
    {
        sat.setPosition(window.getSize().x, rand()%int(window.getSize().y - sat.getGlobalBounds().height));
        sats.push_back(sf::Sprite(sat));
        SatSpawnTimer = 0;
    }
}
Soda::Soda()
{

    if (!sodaTex.loadFromFile(resourcePath()+ "soda.png"))
    {
        throw "Could not load bunny.png!";
    }

    soda.setTexture(sodaTex);
    soda.setScale(sf::Vector2f(0.3f, 0.3f));
    sodas.push_back(sf::Sprite(soda));
}

void Soda::upDateSoda(sf::RenderWindow& window) {

    for (size_t i = 0; i < sodas.size(); i++)
    {
        sodas[i].move(-7.f, 0.f);

        if(sodas[i].getPosition().x < 0 - soda.getGlobalBounds().width)
        {
            sodas.erase(sodas.begin() + i);
        }
    }

    if(SodaSpawnTimer < 40)
    {
        SodaSpawnTimer++;

    }

    if(SodaSpawnTimer >= 40)
    {
        soda.setPosition(window.getSize().x, rand()%int(window.getSize().y - soda.getGlobalBounds().height));
        sodas.push_back(sf::Sprite(soda));
        SodaSpawnTimer = 0;
    }
}
