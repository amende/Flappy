#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define GRAVITY 1400.f
#define INITIAL_SPEED 500.f
#define WALL_SPEED 300.f
#define ESPACE_CENTRAL 200

class Wall
{
    public:
        Wall();
        Wall(sf::RenderWindow* window);
        virtual ~Wall();
        void update(const float& dt);
        void render(sf::RenderTarget* target);
        bool horsCadre();

    protected:
        int m_centralPosition;
        sf::RectangleShape m_topWall;
        sf::RectangleShape m_botWall;

    private:

        //fonctions d'initialisation
        void initVars(sf::RenderWindow* window);
};

#endif // WALL_H
