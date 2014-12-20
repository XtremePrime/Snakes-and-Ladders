#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

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
    int nr_players = 0;
    sf::Vector2i mouse_coords;

    //- Game stuff
    int dice = 0;
    int curr_player = -1;
    bool is_running = true;
    enum State{ MENU, GAME };
    State game_state;

    //- Buttons
    Button two_player_btn;
    Button three_player_btn;
    Button four_player_btn;
    Button roll_btn;
    Button forfeit_btn;
    Button quit_btn;
    //Button two_players_btn;

    void handle_events();
    void update();
    void render();
    void handle_buttons();
    void quit();
public:
	Game(int, int); //- WIDTH, HEIGHT

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