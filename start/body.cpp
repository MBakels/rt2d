/**
* This class describes the Planet behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "body.h"

Body::Body(std::string name, double mass, double diameter) : SpaceEntity() {
	gravityConstant = 6.6742e-11;
	this->name = name;
	this->mass = mass;
	this->diameter = diameter;
	addSprite("assets/planet.tga");
	sprite()->size = Point(diameter, diameter);
}

Body::~Body() {

}

void Body::update(float deltaTime) {
	position += velocity * deltaTime;
}

Vector2 Body::GravitationalForce(SpaceEntity* entity) {
	double dx = position.x - entity->position.x;
	double dy = position.y - entity->position.y;
	double distSQ = dx * dx + dy * dy;
	double dist = sqrt(distSQ);
	double force = (gravityConstant * ((mass + entity->GetMass()) / (dist*dist)));
	double ax = (force * dx) / dist;
	double ay = (force * dy) / dist;
	Vector2 gravitationalForce = Vector2(ax, ay);

	return gravitationalForce;
}

float Body::GetDiameter() {
	return diameter;
}

void Body::SetOrbid(Body* orbitingPlanet, double distance) {
	this->orbitingPlanet = orbitingPlanet;
	this->position = orbitingPlanet->position;
	this->position.x += distance;

	double a = gravityConstant * (orbitingPlanet->GetMass() + mass);
	double b = a / distance;
	double vel = sqrt(b);
	SetVelocity(Vector2(0, vel));
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}

