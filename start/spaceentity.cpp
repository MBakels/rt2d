/**
* This class describes the SpaceEntity behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "spaceentity.h"

SpaceEntity::SpaceEntity() : BasicEntity() {

}

SpaceEntity::~SpaceEntity() {

}

void SpaceEntity::update(float deltaTime) {

}

float SpaceEntity::GetMass() {
	return mass;
}

void SpaceEntity::AddForce(Vector2 force) {
	this->velocity += force;
}

void SpaceEntity::SetVelocity(Vector2 velocity) {
	this->velocity = velocity;
}