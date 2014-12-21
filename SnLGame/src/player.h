#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

/*
Player states:
-1: Forfeit
0:	Playing
1:	Finished
*/

class Player
{
private:
	sf::Vector2f coord;
	sf::RectangleShape rect;
	std::string name;
	// int wins, losses;
	int pos, state, win_pos;
public:
	void init(std::string, int);
	void move(int);
	void render(sf::RenderWindow& window);
	void update();

	void set_position(float, float);

	
	void set_state(int s){state = s;}
	void set_win_pos(int p){win_pos = p;}

	sf::RectangleShape get_rect() {return rect;}
	int get_pos(){return pos;}
	int get_state(){return state;}
	// int get_wins(){return wins;}
	// int get_losses(){return losses;}
	std::string get_name(){return name;}
};

#endif // PLAYER_H