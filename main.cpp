#include <SFML/Graphics.hpp>

#include "game.h"
int main()
{
    srand(time(0)); // initialise randomness (used in the wall generation)
    Game game;
    game.run();

    return 0;
}
