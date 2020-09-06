#include "Field.h"
#include <math.h>

Field::Field(sf::Vector2i resol, int count, float thicknes) : 
	lineCount(count),
	res(resol)
{
	sf::RectangleShape verticalLine(sf::Vector2f(thicknes, res.y));
	sf::RectangleShape horizontalLine(sf::Vector2f(res.x, thicknes));
	verticalLine.setFillColor(sf::Color::Black);
	horizontalLine.setFillColor(sf::Color::Black);

	texture.create(res.x, res.y);

	dst = (float)res.x / lineCount;
	yCount = res.y / dst;

	k = dst / 2;
	for (int i = 0; i < lineCount; i++)
	{
		verticalLine.setPosition(i * dst + k, 0);
		texture.draw(verticalLine);
	}

	for (int i = 0; i < yCount; i++)
	{
		horizontalLine.setPosition(0, i * dst + k);
		texture.draw(horizontalLine);
	}

	sprite.setTexture(texture.getTexture());
}

sf::Vector2i Field::getField()
{
	return sf::Vector2i(lineCount, yCount);
}

sf::Vector2i Field::getRes()
{
	return res;
}

sf::Vector2f Field::getPosIndex(int x, int y)
{
	return sf::Vector2f(x * dst + dst / 2, y * dst + dst / 2);
}

sf::Vector2f Field::getPosIndex(sf::Vector2i index)
{
	return sf::Vector2f(index.x * dst + dst / 2, index.y * dst + dst / 2);
}

sf::Vector2i Field::getNode(sf::Vector2f pos)
{
	sf::Vector2i res;
	res.x = floor(pos.x / dst);
	res.y = floor(pos.y / dst);
	return res;
}

sf::Vector2f Field::getTarget(sf::Vector2i pos)
{
	sf::Vector2f res;
	res.x = round((pos.x - k) / dst) * dst + k;
	res.y = round((pos.y - k) / dst) * dst + k;
	return res;
}

void Field::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}
