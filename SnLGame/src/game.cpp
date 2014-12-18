#include "game.h"

Game::Game(int w, int h)
{
	width = w; height = h;

	//- Setup window
	window.create(sf::VideoMode(width,height), "Snakes and Ladders", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    //- Setup backgroud
	bg_txr.loadFromFile("res/snakesandladders.png");
	bg_spr.setTexture(bg_txr);
	bg_spr.setScale((float)(width-200)/1792, (float)(height)/1350);

	//- Setup font
	font.loadFromFile("res/PressStart2P.ttf")
}

/*Game::Game(int p, int w, int h)
{
	width = w; height = h; nr_players = p;

	//- Setup window
	window.create(sf::VideoMode(width,height), "Snakes and Ladders", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    //- Setup backgroud
	bg_txr.loadFromFile("res/snakesandladders.png");
	bg_spr.setTexture(bg_txr);
	bg_spr.setScale((float)(width-200)/1792, (float)(height)/1350);

	//- Fill players vector
	for(int i = 0; i < p; ++i)
	{
		Player player;
		players.push_back(player);
	}
}*/

void Game::update()
{
	//- Quit game
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
		is_running = false;
	}
}

void Game::render()
{
	//- TODO only render stuff when inside state
	window.draw(bg_spr);

	window.display();
	window.clear();
}

void Game::handle_events()
{
    while(window.pollEvent(event))
    {
    	switch(event.type)
    	{
    		case sf::Event::Closed:
    			is_running = false;
				window.close();
				break;
            default:
                break;
		}
	}
}