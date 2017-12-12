/**
* This class describes the Planet behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "planet.h"

Planet::Planet(std::string name, float mass) : Entity() {
	planetName = name;
	this->mass = mass;
	addSprite("assets/planet.tga");
	sprite()->size = Point(mass / 2, mass / 2);
}

Planet::~Planet() {

}

void Planet::update(float deltaTime) {
	
}

float Planet::GravitationalForce(SpaceShip* entity) {
	float dist = sqrt((entity->position.x - position.x)*(entity->position.x - position.x) + (entity->position.y - position.y)*(entity->position.y - position.y));
	float GravitationalPull = mass * entity->GetMass() / dist;
	return 0.0f;
}