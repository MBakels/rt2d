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
	sprite()->size = Point(mass / 100, mass / 100);
}

Planet::~Planet() {

}

void Planet::update(float deltaTime) {
	
}

Vector2 Planet::GravitationalForce(SpaceShip* entity) {
	float dx = position.x - entity->position.x;
	float dy = position.y - entity->position.y;
	float distSQ = dx * dx + dy * dy;
	float dist = sqrt(distSQ);
	float force = mass * entity->GetMass() / distSQ;
	float ax = (force * dx) / dist;
	float ay = (force * dy) / dist;
	Vector2 gravitationalForce = Vector2(ax / entity->GetMass(), ay / entity->GetMass());

	return gravitationalForce;
}