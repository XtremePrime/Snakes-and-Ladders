#include "button.h"

void Button::init(const std::string msg, int x, int y, int w, int h)
{
	//- Setup text
	font.loadFromFile("res/PressStart2P.ttf");
	text.setString(msg);
	text.setFont(font);
	text.setPosition(x+11, y+11);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(11);

	box.left = x;
	box.top = y;
	box.width = w;
	box.height = h;

	txr.loadFromFile("res/red_button.png");
	txr.setSmooth(true);

	//- Setup RectangleShape
	rect.setSize(sf::Vector2f((float)w, (float)h));
	rect.setTexture(&txr, false);
	rect.setPosition(x, y);
}

bool Button::was_clicked(sf::Vector2i mouse)
{
	if(box.contains(mouse))
		return true;

	return false;
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(rect);
	window.draw(text);
}
