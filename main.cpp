#include "Game.h"

int main() {
    //Init game engine
    Game game;

    //Game loop
    while (game.isRunning()) {
        //Update
        game.update(game.getMousePos());
        //Render 
        game.render(game.getWindow());
    }

    return 0;
}