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

	//- Setup dice number text
	dice_txt.setCharacterSize(20);
	dice_txt.setColor(sf::Color::White);
	dice_txt.setFont(font);
	dice_txt.setPosition(BUTTON_X, 300);

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
	//- Update mouse coords
	mouse_coords = sf::Mouse::getPosition(window);

	for(int i = 0; i < nr_players; ++i)
		players[i].update();

	//- Quit game
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		quit();
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

			window.draw(dice_txt);
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
				auto str = [=] () mutable -> std::string {std::ostringstream temp; temp<<i; return temp.str();}();
				p.init("Player "+i, 1);
				players.push_back(p);
			}

			game_state = GAME; // Change game state
		}
	}
	else if(game_state == GAME)
	{
		if(roll_btn.was_clicked(mouse_coords)){
			//- Generate+Print dice
			dice = rand()%6+1;
			auto str = [=] () mutable -> std::string {std::ostringstream temp; temp<<dice; return temp.str();}();
			dice_txt.setString(str);
			
			//- Move curr_player
			players[curr_player].move(players[curr_player].get_pos() + dice);
			std::cout << "\"Player " << curr_player << "\" rolled: " << dice << " (New player position:" << players[curr_player].get_pos() << ")\n"; 
			
			//- Check if player won
			if(players[curr_player].get_pos() >= 100){
				players[curr_player].set_state(1);
				//players[curr_player].set_state(nr_finished_players++);
			}

			change_turn(curr_player);
		}
		else if(forfeit_btn.was_clicked(mouse_coords)){
			players[curr_player].set_state(-1); //- (-1) = Lost game
			std::cout << "Player " << curr_player << " has forfeit!\n";
			change_turn(curr_player);
		}

	}
}

void Game::change_turn(int& pl)
{
	do{
		if(pl >= nr_players-1)
			pl = 0;
		else
			pl++;
	}while(players[pl].get_state() == -1);
}

void Game::quit()
{
	window.close();
	is_running = false;
}