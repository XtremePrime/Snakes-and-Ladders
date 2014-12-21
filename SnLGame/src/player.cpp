#include "player.h"

void Player::init(std::string n="#ERROR", int p=-1)
{
	name = n;
	pos = p;
	// wins = 0;
	// losses = 0;
	state = 0;
	win_pos = 0;

	rect.setSize(sf::Vector2f(10.f, 10.f));
	rect.setPosition(coord.x, coord.y);
}

void Player::update()
{
	rect.setPosition(coord.x, coord.y);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(rect);
}

void Player::move(int p)
{
	pos = p;
}

void Player::set_position(float x, float y)
{
	coord.x = x;
	coord.y = y;
}