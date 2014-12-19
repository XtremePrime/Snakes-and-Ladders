#include "button.h"

void Button::init(const std::string msg, int x, int y, int w, int h)
{
	font.loadFromFile("res/PressStart2P.ttf");

	text.setString(msg);
	text.setFont(font);
	text.setPosition((x/2)+11, (y/2)+11);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(11);

	box.left = x;
	box.top = y;
	box.width = w;
	box.height = h;

	txr.loadFromFile("res/red_button.png");
	spr.setTexture(txr);
	spr.setScale((float)(w)/600, (float)(h)/292);
}

bool Button::was_clicked(sf::Vector2i mouse)
{
	if(box.contains(mouse))
		return true;

	return false;
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(spr);
	window.draw(text);
}
