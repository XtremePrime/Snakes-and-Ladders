#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "player.h"
#include "button.h"

class Game
{
private:
	//- Window stuff
	sf::ContextSettings settings;
	int width, height;
    sf::RenderWindow window;
    sf::Event event;
    std::string version;
    
    //- Drawy stuff
    sf::Font font;
    sf::Texture bg_txr;
    sf::Sprite bg_spr;

    //- Player stuff
    std::vector<Player> players;
    int nr_players;
    sf::Vector2i mouse_coords;

    //- Game stuff
    bool is_running = true;
    enum State{ MENU, GAME };
    State game_state;

    //- Buttons
    Button quit_btn;
    //Button two_players_btn;

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