#include "game.h"

#define BUTTON_X 680
#define BUTTON_WIDTH 165
#define BUTTON_HEIGHT 40

Game::Game(int w, int h)
{
	width = w; height = h;
	srand(time(NULL));

	//- Setup window
	settings.antialiasingLevel = 8;
	version = "1.0";
	window.create(sf::VideoMode(width,height), "Snakes and Ladders v"+version, sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);


    //- Setup backgroud
	bg_txr.loadFromFile("res/snakesandladders.png");
	bg_txr.setSmooth(true);
	bg_spr.setTexture(bg_txr);
	bg_spr.setScale((float)(width-200)/1792, (float)(height)/1350);

	//- Setup font
	font.loadFromFile("res/PressStart2P.ttf");

	//- Start in the menu
	game_state = MENU;

	//- Buttons
	two_player_btn.init("Two players", BUTTON_X, 50, BUTTON_WIDTH, BUTTON_HEIGHT);
    three_player_btn.init("Three players", BUTTON_X, 100, BUTTON_WIDTH, BUTTON_HEIGHT);
    four_player_btn.init("Four players", BUTTON_X, 150, BUTTON_WIDTH, BUTTON_HEIGHT);
    roll_btn.init("Roll dice", BUTTON_X, 510, BUTTON_WIDTH, BUTTON_HEIGHT);
    forfeit_btn.init("Forfeit", BUTTON_X, 560, BUTTON_WIDTH, BUTTON_HEIGHT);
	quit_btn.init("Quit", BUTTON_X, 560, BUTTON_WIDTH, BUTTON_HEIGHT);
}

void Game::update()
{
	//- Always update mouse coords
	mouse_coords = sf::Mouse::getPosition(window);

	//- Quit game
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		quit();
	}
}

void Game::render()
{
	window.draw(bg_spr);

	//- Render buttons
	switch(game_state)
	{
		case MENU:
			two_player_btn.render(window);
			three_player_btn.render(window);
			four_player_btn.render(window);
			quit_btn.render(window);
		break;
		case GAME:
			roll_btn.render(window);
			forfeit_btn.render(window);

			for(int i = 0; i < nr_players; ++i)
				players[i].render(window);
		break;
	}
	
	window.display();
	window.clear();
}

void Game::handle_events()
{
    while(window.pollEvent(event))
    {
    	switch(event.type)
    	{
    		case sf::Event::MouseButtonReleased:
    			handle_buttons();
    		break;

    		case sf::Event::Closed:
    			quit();
			break;

			default:
			break;
		}
	}
}

void Game::handle_buttons()
{
	if(game_state == MENU)
	{
		if(two_player_btn.was_clicked(mouse_coords))
			nr_players = 2;
		else if(three_player_btn.was_clicked(mouse_coords))
			nr_players = 3;
		else if(four_player_btn.was_clicked(mouse_coords))
			nr_players = 4;
		else if(quit_btn.was_clicked(mouse_coords)){
			quit();
			return;
		}

		//- Nr Players was selected
		if(nr_players != 0)
		{
			for(int i = 0; i < nr_players; ++i)
			{
				Player p;
				p.init("Player #"+i, 1);
				players.push_back(p);
			}

			game_state = GAME; // Change game state
		}
	}
	else if(game_state == GAME)
	{
		if(roll_btn.was_clicked(mouse_coords)){
			dice = rand()%6+1;
			std::cout << "dice: " << dice << "\n";
		}
		else if(forfeit_btn.was_clicked(mouse_coords))
			players[curr_player].set_state(-1); //- (-1) = Lost game
	}
}

void Game::quit()
{
	window.close();
	is_running = false;
}