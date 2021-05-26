#include "Game.h"

Game::Game()
{
    //ctor
    initWindow();
    initVars();
}

void Game::initVars(){
    m_bird=Bird(m_window);
    //m_wall=Wall(m_window);
    m_collide= false;
    m_maxWalls=10;
    m_wallSpawnTimer=20.f;
    m_wallSpawnTimerMax=100.f;
}

void Game::initWindow(){
    m_videoMode=sf::VideoMode::getDesktopMode();
    m_window=new sf::RenderWindow(m_videoMode,"Flappy");
    m_window->setFramerateLimit(60);
}


Game::~Game()
{
    //dtor
    delete m_window;
}

void Game::render(){

    m_window->clear();
    m_bird.render(m_window);
    renderWalls();
    //m_wall.render(m_window);
    m_window->display();
}


void Game::update(){
    m_bird.update(m_dt);
    updateWalls();
    //m_wall.update(m_dt);
    checkCollision();
    if (m_collide){
        endGame();
    }
}

void Game::updateDt(){
    /*
    get the delta time
    */
    m_dt=m_dtClock.restart().asSeconds();

}

void Game::updateEvents(){
    while (m_window->pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
                m_window->close();
            if (m_event.type == sf::Event::KeyReleased)
            switch (m_event.key.code){
                    case sf::Keyboard::Space :
                        m_bird.impulse();
                        break;
                    default:
                        break;
            }

        }
}

void Game::spawnWall(){
    m_wall= Wall(m_window);
    m_walls.push_back(m_wall);
}


void Game::updateWalls(){
    /*
    return void
    spawn walls and update timer
    don't spawn if number of walls is already max
    moove walls
    */
    if (m_walls.size()<m_maxWalls){
        if (m_wallSpawnTimer>=m_wallSpawnTimerMax){
            spawnWall();
            m_wallSpawnTimer= 0.f;
        }
        else{
            m_wallSpawnTimer+=1.f;
        }
    }
    for (auto &e : m_walls)
    {
        e.update(m_dt);
    }
    //remove enemies at the end of the screen
    for (auto &e : m_walls)
    {
        if (e.horsCadre()){
            m_walls.erase(m_walls.begin());

        }
    }
}


void Game::renderWalls(){
    for (auto &e : m_walls)
    {
        e.render(m_window);
    }
}
void Game::checkCollision(){
    /*
    for all walls in the list, check if there is a collision
    also check if the bird tries to go out of the window
    */
    for (auto &e : m_walls){
        if ((m_bird.getShape().getGlobalBounds().intersects(e.getTopWall().getGlobalBounds()))||(m_bird.getShape().getGlobalBounds().intersects(e.getBotWall().getGlobalBounds()))){
            m_collide=true;
        }
    }
    if ((m_bird.getShape().getPosition().y<0) || (m_bird.getShape().getPosition().y>m_window->getSize().y)){
        m_collide=true;
    }
}

void Game::run(){
    while (m_window->isOpen())
    {
        updateDt();
        updateEvents();
        update();
        render();
    }
}

void Game::endGame(){
    m_window->close();
    std::cout<<"congrats, you died" << std::endl;
}



