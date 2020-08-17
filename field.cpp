#include "field.h"
#include <iostream>


Field::Field(sf::Vector2i resol, int count, float thicknes):
	lineCount(count)
{
	sf::RectangleShape verticalLine(sf::Vector2f(thicknes, resol.y));
	sf::RectangleShape horizontalLine(sf::Vector2f(resol.x, thicknes));
	verticalLine.setFillColor(sf::Color::Black);
	horizontalLine.setFillColor(sf::Color::Black);

	texture.create(resol.x, resol.y);


	dst = (float)resol.x / lineCount;
	yCount = resol.y / dst;

	for (int i = 1; i <= lineCount; i++) {
		verticalLine.setPosition(i * dst, 0);
		texture.draw(verticalLine);
	}

	k = ((float)resol.y - (yCount - 1) * dst + dst) / 4;


	for (int i = 0; i < yCount; i++) {
		horizontalLine.setPosition(0, i * dst+k);
		texture.draw(horizontalLine);
	}

	sprite.setTexture(texture.getTexture());
}

sf::Vector2i Field::getField() {
	return sf::Vector2i(lineCount, yCount);
}

sf::Vector2i Field::getNode(sf::Vector2f pos) {
	sf::Vector2i res;
	res.x = round(pos.x / dst);
	res.y = floor(pos.y / dst);
	return res;
}

sf::Vector2f Field::getPos(sf::Vector2i pos) {
	sf::Vector2f res;
	res.x = round(pos.x / dst)*dst;
	res.y = floor(pos.y / dst )*dst+k;
	return res;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}