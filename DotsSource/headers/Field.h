#pragma once
#include <SFML/Graphics.hpp>
class Field : public sf::Drawable
{
public:
	Field(sf::Vector2i resolution, int lineCount, float thicknes);
	sf::Vector2f getTarget(sf::Vector2i pos); //get pos of close node
	sf::Vector2i getNode(sf::Vector2f pos); //get node index from pos
	sf::Vector2i getField();
	sf::Vector2i getRes();
	sf::Vector2f getPosIndex(int x, int y); //get pos from index
private:
	sf::Vector2i res;
	float dst; //distance between lines
	int yCount;
	float k;
	int lineCount;
	sf::RenderTexture texture;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

