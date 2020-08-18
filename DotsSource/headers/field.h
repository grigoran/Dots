#pragma once
#include <SFML/Graphics.hpp>
class Field : public sf::Drawable
{
public:
	Field(sf::Vector2i resolution, int lineCount, float thicknes);
	sf::Vector2f getPos(sf::Vector2i pos);
	sf::Vector2i getNode(sf::Vector2f pos);
	sf::Vector2i getField();
private:
	float dst; //distance between lines
	int yCount;
	float k;
	int lineCount;
	sf::RenderTexture texture;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

