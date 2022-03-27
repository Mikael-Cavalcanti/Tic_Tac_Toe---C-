#include "game.hpp"
#include "point.hpp"

int main(int argc, char const *argv[])
{
    GameManager *game = new GameManager();

    game->StartGame();

    game->~GameManager();

    return 0;
}
