#include "Contours.h"
#include <iostream>
#include <math.h>

Contours::Contours(Field *_field)
{
  field = _field;
  stage=0;
  contours.reserve(10);
  contoursStates.reserve(10);
  contoursLenght.reserve(10);
  nowContourDraw = -1;
  drawNodeNumber=0;
}

void Contours::add(Node *start)
{
  contours.push_back(start);
  contoursStates.push_back(false);
  Node *now = start;
  int count=0;
  
  do
  {
    count++;
    now = now->getNext();
  } while (now != start);
  contoursLenght.push_back(count);
}

void Contours::update(float speed)
{
  for (int i = 0; i < contours.size(); i++)
  {
    if (contoursStates[i] == false)
    {
      if (nowContourDraw == i)
      {
        float k1=3;
        float k2=10;
        float phase=sin(M_PI*drawNodeNumber/contoursLenght[i])/k2;
        stage += speed*k1+phase;
        if (stage >= 1)
        {
          if (drawNodeNumber < contoursLenght[i]){
            drawNodeNumber++;
          }
          else
          {
            std::cout<<"Drawed\n";
            drawNodeNumber = 0;
            contoursStates[i] = true;
            nowContourDraw = -1;
          }
          stage = 0;
        }
      }
      else if (nowContourDraw == -1)
        nowContourDraw = i;
    }
  }
}

void Contours::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  Node *now;
  sf::Vector2f startPoint;
  sf::Vector2f endPoint;
  Line line;
  for (int i = 0; i < contours.size(); i++)
  {
    if (contoursStates[i] == false)
      continue;
    now = contours[i];
    for (int j = 0; j < contoursLenght[i]; j++)
    {
      startPoint = field->getPosIndex(now->getIndex());
      now = now->getNext();
      endPoint = field->getPosIndex(now->getIndex());
      line.set(startPoint, endPoint, now->getColor(), 1);
      target.draw(line);
    }
  }

  if (nowContourDraw == -1)
    return;
  
  now=contours[nowContourDraw];
  for (int i = 0; i < drawNodeNumber; i++)
  {
    startPoint = field->getPosIndex(now->getIndex());
    now = now->getNext();
    endPoint = field->getPosIndex(now->getIndex());
    if (i != drawNodeNumber-1)
      line.set(startPoint, endPoint, now->getColor(), 1);
    else
      line.set(startPoint, endPoint, now->getColor(), stage);
    target.draw(line);
  }
}
