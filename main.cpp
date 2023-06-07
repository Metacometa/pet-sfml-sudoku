#include "Game.h"

int main() {
    //Init game engine
    Game game;

    //Game loop
    while (game.isRunning()) {
        //Update
        game.update();
        //Render 
        game.render(game.getWindow());
    }

    return 0;
}