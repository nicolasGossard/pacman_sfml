#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

int main()
{
    // Window
    constexpr unsigned int windowWidth = 684;
    constexpr unsigned int windowHeight = 756;
    constexpr const char *windowTitle = "PACMAN";
    constexpr sf::Color windowColor = sf::Color::Black;

    // Settings
    constexpr unsigned int fpsMax = 120;
    constexpr bool keyRepeat = false;

    sf::RenderWindow window(sf::VideoMode(
        {windowWidth, windowHeight}), windowTitle);
    
    window.setFramerateLimit(fpsMax);
    window.setKeyRepeatEnabled(keyRepeat);

    Game game;
    GameInit(&game, windowWidth, windowHeight);

    sf::Texture mapTexture;
    mapTexture.setSmooth(false);

    if (!mapTexture.loadFromFile("Sprites/map.png"))
    {
        std::cout << "Erreur chargement map.png\n";
        return 1;
    }

    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale({3.f, 3.f});

    std::vector<std::string> map = {
        "############################",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#o####.#####.##.#####.####o#",
        "#.####.#####.##.#####.####.#",
        "#..........................#",
        "#.####.##.########.##.####.#",
        "#.####.##.########.##.####.#",
        "#......##....##....##......#",
        "######.##### ## #####.######",
        "     #.##### ## #####.#     ",
        "     #.##          ##.#     ",
        "     #.## ######## ##.#     ",
        "######.## #      # ##.######",
        "      .   #      #   .      ",
        "######.## #      # ##.######",
        "     #.## ######## ##.#     ",
        "     #.##          ##.#     ",
        "     #.## ######## ##.#     ",
        "######.## ######## ##.######",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#o..##.......  .......##..o#",
        "###.##.##.########.##.##.###",
        "###.##.##.########.##.##.###",
        "#......##....##....##......#",
        "#.##########.##.##########.#",
        "#.##########.##.##########.#",
        "#..........................#",
        "############################"
    };

    while (window.isOpen())
    {
        GameUpdate(&game);

        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mousePressed->button == sf::Mouse::Button::Left)
                {

                }
            }
        }
        
        window.clear(windowColor);
        window.draw(mapSprite);
        window.display();
    }

    return 1;
}

/*
clang++ main.cpp game.cpp -o sfml_test \
-std=c++17 \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system
 
./sfml_test
*/