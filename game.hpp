#ifndef GAME_HPP
#define GAME_HPP

struct Game
{
    // Window
    int windowWidth;
    int windowHeight;
    
    // Player
    int playerSpeed;

    // Enemies
    int enemySpeed;

    // Score
    int currentScore;
    int highScore;

    // State
    bool win;
    bool gameOver;

    // Sounds
};

void GameInit(Game *game, int screen_width, int screen_height);
void GameUpdate(Game *game);
void GameDraw(Game *game);
void GameUnload(Game *game);

#endif
