#include "Dot.h"
#include <iostream>
Dot::Dot(sf::Vector2i _field, sf::Vector2i res) :
	field(_field)
{
	mesh = new char* [field.x];
	for (int i = 0; i < field.x; i++) {
		mesh[i] = new char[field.y];
		for (int j = 0; j < field.y; j++) {
			mesh[i][j] = 0;
		}
	}
	texture.create(res.x, res.y);
}

bool Dot::push(sf::Vector2f pos, sf::Vector2i node, sf::Color col, char team) {
	if (node.x < field.x && node.y < field.y && node.x >= 0 && node.y >= 0)
		if (mesh[node.x][node.y] == 0) {
			sf::CircleShape circle(10.0f);
			circle.setOrigin(10, 10);
			circle.setPosition(pos);
			circle.setFillColor(col);

			texture.draw(circle);
			texture.display();
			sprite.setTexture(texture.getTexture());
			mesh[node.x][node.y] = team;
			//TODO: remove later
			//***********************************
			system("clear");
			for(int i=0; i<field.y; i++){
				for(int j=0; j<field.x; j++){
					std::cout<<(int)mesh[j][i]<<" ";
				}
				std::cout<<"\n";
			}
			//***********************************
			return true;
		}
	return false;
}


void Dot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}


Dot::~Dot() {
	for (int i = 0; i < field.y; i++) {
		delete[] mesh[i];
	}
	delete[] mesh;
}
