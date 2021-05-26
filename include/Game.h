#ifndef GAME_H
#define GAME_H


#include "Bird.h"
class Game
{
    public:
        Game();
        virtual ~Game();
        void render();
        void update();
        void updateEvents();
        void updateDt();
        void run();
        void updateWalls();
        void renderWalls();
        void spawnWall();
        void checkCollision();
        void endGame();

    protected:
        //init functions
        void initVars();
        void initWindow();
        void initWalls();

        //attributs
        sf::RenderWindow* m_window;
        sf::VideoMode m_videoMode;
        sf::Event m_event;

        //clock
        sf::Clock m_dtClock;
        float m_dt;

        //game
        Bird m_bird;
        std::vector<Wall> m_walls;
        Wall m_wall;

        float m_wallSpawnTimer;
        float m_wallSpawnTimerMax;
        int m_maxWalls;

        bool m_collide;


    private:
};

#endif // GAME_H
