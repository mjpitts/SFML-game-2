#include "Game.h"

int main()
{
    // Init srand seed
    srand(static_cast<unsigned>(time(NULL)));

    // Init game object
    Game game;

    // Game loop
    while (game.running()) {
        
        game.update();
        game.render();

    }

    return 0;
}
