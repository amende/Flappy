#ifndef BIRD_H
#define BIRD_H


#include "Wall.h"
class Bird
{
    public:
        Bird();
        Bird(sf::RenderWindow* window);
        virtual ~Bird();

        void render(sf::RenderTarget* target);
        void update(const float& dt);
        void impulse();
        sf::CircleShape getShape();

    protected:
        //shaphe
        sf::CircleShape m_shape;
        float m_speedY;


        //init functions
        void initCircle(sf::RenderWindow* window);
        void initVars();
    private:
};

#endif // BIRD_H
