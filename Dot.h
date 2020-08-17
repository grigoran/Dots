#pragma once
#include <SFML/Graphics.hpp>
class Dot: public sf::Drawable
{
public:
	Dot(sf::Vector2i _field, sf::Vector2i res);
	bool push(sf::Vector2f pos,sf::Vector2i node, sf::Color col, char team);
	~Dot();
private:
	sf::Vector2i field;
	char** mesh;
	sf::RenderTexture texture;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

