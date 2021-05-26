#include "Wall.h"

Wall::Wall()
{
    //ctor
}

Wall::Wall(sf::RenderWindow* window){
    initVars(window);
}


Wall::~Wall()
{
    //dtor
}



void Wall::initVars(sf::RenderWindow* window){
    m_centralPosition = 180+rand()%((int)window->getSize().y-360);

    //top wall settings
    m_topWall = sf::RectangleShape(sf::Vector2f(50.f,m_centralPosition-ESPACE_CENTRAL/2));
    m_topWall.setFillColor(sf::Color::Magenta);
    m_topWall.setPosition((int)window->getSize().x-200,0);

    //bot wall settings
    m_botWall = sf::RectangleShape(sf::Vector2f(50.f,window->getSize().y-150));
    m_botWall.setPosition((int)window->getSize().x-200,m_centralPosition+ESPACE_CENTRAL/2);
    m_botWall.setFillColor(sf::Color::Green);

}


void Wall::update(const float& dt){
    m_topWall.move(-dt*WALL_SPEED,0);
    m_botWall.move(-dt*WALL_SPEED,0);
}

void Wall::render(sf::RenderTarget* target){
    target->draw(m_topWall);
    target->draw(m_botWall);
}


bool Wall::horsCadre(){
    return m_topWall.getPosition().x < 0;
}

