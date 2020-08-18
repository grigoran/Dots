#include "field.h"
#include <iostream>
#include <math.h>


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
	std::cout<<yCount<<std::endl;

	k = dst/2;
	for (int i = 0; i <lineCount; i++) {
		verticalLine.setPosition(i * dst+k, 0);
		texture.draw(verticalLine);
	}


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
	res.x = floor(pos.x / dst);
	res.y = floor(pos.y / dst);
	return res;
}

sf::Vector2f Field::getPos(sf::Vector2i pos) {
	sf::Vector2f res;
	res.x = round((pos.x-k) / dst)*dst+k;
	res.y = round((pos.y-k) / dst)*dst+k;
	return res;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}
