#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
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
	int pos, wins, losses, state, win_pos;
public:
	void init(std::string, int);
	void move(int);
	void render(sf::RenderWindow& window);

	void set_state(int s){state = s;}
	int get_pos(){return pos;}
	int get_wins(){return wins;}
	int get_losses(){return losses;}
	std::string get_name(){return name;}
};

#endif // PLAYER_H