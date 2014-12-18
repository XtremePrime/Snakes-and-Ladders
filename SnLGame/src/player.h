#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <string>

class Player
{
private:
	sf::Vector2i coord;
	std::string name;
	int pos, wins, losses;
public:
	Player();
	Player(std::string, int, int, int);
	void move(int);

	int get_pos(){return pos;}
	int get_wins(){return wins;}
	int get_losses(){return losses;}
	std::string get_name(){return name;}
};

#endif // PLAYER_H