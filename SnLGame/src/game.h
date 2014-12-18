#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "player.h"

class Game
{
private:
	int width, height;
    sf::RenderWindow window;
    sf::Event event;
    
    sf::Font font;
    sf::Texture bg_txr;
    sf::Sprite bg_spr;

    std::vector<Player> players;
    int nr_players;

    bool is_running = true;

    void handle_events();
    void update();
    void render();
public:
	Game(int, int); //- WIDTH, HEIGHT
    //Game(int, int, int); //- PLAYERS, WIDTH, HEIGH

	void run()
	{
		while(is_running)
		{
			handle_events();
			update();
			render();
		}
	}
};

#endif // GAME_H