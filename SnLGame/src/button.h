#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
	//std::string msg;
	sf::Text text;
	sf::Rect<int> box;
	sf::Font font;

	sf::Texture txr;
	sf::Sprite spr;
public:
	void init(const std::string, int, int, int, int);
	bool was_clicked(sf::Vector2i);
	void render(sf::RenderWindow& window);

	sf::Rect<int> get_box() { return box; }
};

#endif // BUTTON_H