/**
* This class describes the Planet behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "body.h"

Body::Body(std::string name, float mass) : SpaceEntity() {
	this->name = name;
	this->mass = mass;
	addSprite("assets/planet.tga");
	sprite()->size = Point(mass / 1000, mass / 1000);
	radius = sprite()->size.x;
	orbidSet = false;
	pauseOrbid = false;
}

Body::~Body() {

}

void Body::update(float deltaTime) {
	if (orbidSet && !pauseOrbid) {
		OrbidBody(deltaTime);
	}
}

Vector2 Body::GravitationalForce(SpaceEntity* entity) {
	double dx = position.x - entity->position.x;
	double dy = position.y - entity->position.y;
	double distSQ = dx * dx + dy * dy;
	double dist = sqrt(distSQ);
	double force = mass * entity->GetMass() / distSQ;
	double ax = (force * dx) / dist;
	double ay = (force * dy) / dist;
	Vector2 gravitationalForce = Vector2(ax / entity->GetMass(), ay / entity->GetMass());

	return gravitationalForce;
}

void Body::SetOrbid(Body* orbitingPlanet, float orbitingHeight, float orbitingSpeed, float angle) {
	this->orbitingPlanet = orbitingPlanet;
	this->orbitingPlanetX = orbitingPlanet->position.x;
	this->orbitingPlanetY = orbitingPlanet->position.y;
	this->orbitingHeight = orbitingHeight;
	this->orbitingSpeed = orbitingSpeed;
	this->angle = angle;
	orbidSet = true;

	OrbidBody(0.0f);
}

void Body::OrbidBody(float deltaTime) {
	position.x = orbitingPlanetX + sin(angle) * (orbitingPlanet->GetRadius() + orbitingHeight);
	position.y = orbitingPlanetY + cos(angle) * (orbitingPlanet->GetRadius() + orbitingHeight);
	angle += orbitingSpeed * deltaTime;
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}

