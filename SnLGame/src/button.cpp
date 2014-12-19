#include "button.h"

Button::Button(std::string msg, int x, int y, int w, int h)
{
	font.loadFromFile("res/PressStart2P.ttf");

	text.setString(msg);
	text.setFont(font);
	text.setPosition((x/2)-11, (y/2)-11);
	text.setCharacter(11);

	box.left = x;
	box.top = y;
	box.width = w;
	box.height = h;
}

bool Button::was_clicked(sf::Vector2i mouse)
{
	if(box.contains(mouse))
		return true;

	return false;
}

void render(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(box);
}
