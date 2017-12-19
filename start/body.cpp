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
}

Body::~Body() {

}

void Body::update(float deltaTime) {
	if (orbidSet) {
		//OrbidBody();
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

float Body::GetRadius() {
	return radius;
}

void Body::SetOrbid(Body* orbitingPlanet, float radiusOrbitingPlanetX, float radiusOrbitingPlanetY, float orbitingSpeed, float angle) {
	this->orbitingPlanet = orbitingPlanet;
	this->orbitingPlanetX = orbitingPlanet->position.x;
	this->orbitingPlanetY = orbitingPlanet->position.y;
	this->radiusOrbitingPlanetX = radiusOrbitingPlanetX;
	this->radiusOrbitingPlanetY = radiusOrbitingPlanetY;
	this->orbitingSpeed = orbitingSpeed;
	this->angle = angle;
	orbidSet = true;

	OrbidBody();
}

void Body::OrbidBody() {
	position.x = orbitingPlanetX + sin(angle) * (orbitingPlanet->GetRadius() + radiusOrbitingPlanetX);
	position.y = orbitingPlanetY + cos(angle) * (orbitingPlanet->GetRadius() + radiusOrbitingPlanetY);
	angle += orbitingSpeed;
}

std::string Body::GetName() {
	return name;
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}