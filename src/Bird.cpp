#include "Bird.h"

Bird::Bird(sf::RenderWindow* window)
{
    //ctor
    initCircle(window);
    initVars();
}


Bird::Bird()
{

}
Bird::~Bird()
{
    //dtor
}


void Bird::initCircle(sf::RenderWindow* window){
    m_shape=sf::CircleShape(25.f);
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(sf::Vector2f((float)window->getSize().x/2,(float)window->getSize().y/2));
}

void Bird::initVars(){
    m_speedY=-INITIAL_SPEED;
}

void Bird::render(sf::RenderTarget* target){
    target->draw(m_shape);
}

void Bird::update(const float& dt){
    m_shape.setPosition(m_shape.getPosition().x,m_shape.getPosition().y+dt*m_speedY);
    m_speedY+=GRAVITY*dt;
}


void Bird::impulse(){
    m_speedY=-INITIAL_SPEED;
}

