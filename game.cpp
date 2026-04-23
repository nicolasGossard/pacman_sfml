#include "game.hpp"

void GameInit(Game *game, int windowWidth, int windowHeight)
{
    game->windowWidth = windowWidth;
    game->windowHeight = windowHeight;

    game->playerSpeed = 2;
    game->enemySpeed = 2;

    game->currentScore = 0;
    game->highScore = 0;

    game->win = false;
    game->gameOver = false;
}

void GameUpdate(Game *game)
{

}

void GameDraw(Game *game)
{

}

void GameUnload(Game *game)
{
    
}