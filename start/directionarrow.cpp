/**
* This class describes the DirectionArrow behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "directionarrow.h"

DirectionArrow::DirectionArrow(Entity* target) : Entity() {
	this->target = target;
	addSprite("assets/arrow.tga");
}

DirectionArrow::~DirectionArrow() {

}

void DirectionArrow::update(float deltaTime) {
	float angle = atan2(target->position.y - position.y, target->position.x - position.x);
	rotation = Point3(0, 0, (PI * 1.5) + angle);
}