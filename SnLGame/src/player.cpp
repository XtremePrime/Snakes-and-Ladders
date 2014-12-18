#include "player.h"

Player::Player()
{
	name = "";
	pos = 0;
	wins = 0; 
	losses = 0;
}

Player::Player(std::string n, int p, int w, int l)
{
	name = n;
	pos = p;
	wins = w;
	losses = l;
}

void Player::move(int p)
{
	this->pos = p;
}