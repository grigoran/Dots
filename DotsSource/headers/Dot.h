#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
class Dot: public sf::Drawable
{
public:
	Dot(Field* _field);
	bool push(sf::Vector2f pos, char team);
	void clear();
	void undo();
	static sf::Color getColor(char team);
	~Dot();
private:
	Field* field;
	sf::Vector2i last;
	char** mesh;
	sf::RenderTexture dotTex; //texture for dots
	sf::RenderTexture lnTex; //texture for lines
	//sprites for dots and lines
	sf::Sprite lnSprite;
	sf::Sprite dotsSpr;
	void redraw();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

