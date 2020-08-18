#include "Dot.h"
#include <iostream>

sf::Color Dot::getColor(char team)
{
	switch (team)
	{
	case 1:
		return sf::Color::Red;
		break;
	case 2:
		return sf::Color::Green;
		break;
	case 3:
		return sf::Color::Blue;
		break;
	case 4:
		return sf::Color::Yellow;
		break;
	default:
		return sf::Color::Black;
		break;
	}
}

Dot::Dot(Field* _field)
{
	field=_field;
	mesh = new char *[field->getField().x];
	for (int i = 0; i < field->getField().x; i++)
	{
		mesh[i] = new char[field->getField().y];
		for (int j = 0; j < field->getField().y; j++)
		{
			mesh[i][j] = 0;
		}
	}
	dotTex.create(field->getRes().x, field->getRes().y);
}

bool Dot::push(sf::Vector2f pos, char team)
{
	sf::Vector2i node=field->getNode(pos);
	if (node.x < field->getField().x && node.y < field->getField().y && node.x >= 0 && node.y >= 0)
		if (mesh[node.x][node.y] == 0)
		{
			sf::CircleShape circle(10.0f);
			circle.setOrigin(10, 10);
			circle.setPosition(pos);
			circle.setFillColor(getColor(team));
			dotTex.draw(circle);
			dotTex.display();
			dotsSpr.setTexture(dotTex.getTexture());
			mesh[node.x][node.y] = team;
			last = node;
			return true;
		}
	return false;
}

void Dot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(dotsSpr);
}

void Dot::clear()
{
	dotTex.clear(sf::Color::Transparent);
	for (int i = 0; i < field->getField().x; i++)
	{
		for (int j = 0; j < field->getField().y; j++)
		{
			mesh[i][j] = 0;
		}
	}
}

void Dot::undo()
{
	mesh[last.x][last.y] = 0;
	redraw();
}

void Dot::redraw()
{
	//float dst = (float)dotTex.getSize().x / field->getField().x;
	dotTex.clear(sf::Color::Transparent);
	sf::CircleShape circle(10.0f);
	circle.setOrigin(10, 10);
	for (int i = 0; i < field->getField().x; i++)
	{
		for (int j = 0; j < field->getField().y; j++)
		{
			if(mesh[i][j]!=0){
				circle.setPosition(field->getPosIndex(i,j));
				circle.setFillColor(getColor(mesh[i][j]));
				dotTex.draw(circle);
			}
		}
	}
}

Dot::~Dot()
{
	for (int i = 0; i < field->getField().x; i++)
	{
		delete[] mesh[i];
	}
	delete[] mesh;
}
