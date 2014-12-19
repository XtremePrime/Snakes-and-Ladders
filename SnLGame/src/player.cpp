#include "player.h"

void Player::init(std::string n="#ERROR", int p=-1, int w=-1, int l=-1)
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