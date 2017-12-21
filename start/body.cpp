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
	this->radius = diameter / 2;
	addSprite("assets/planet.tga");
	sprite()->size = Point(diameter, diameter);
}

Body::~Body() {

}

void Body::update(float deltaTime) {
	position += velocity;
}

Vector2 Body::GravitationalForce(SpaceEntity* entity) {
	double dx = position.x - entity->position.x;
	double dy = position.y - entity->position.y;
	double distSQ = dx * dx + dy * dy;
	double dist = sqrt(distSQ);
	//double force = mass * entity->GetMass() / distSQ;
	double force = (gravityConstant * (mass + entity->GetMass()) / (dist*dist));
	double ax = (force * dx) / dist;
	double ay = (force * dy) / dist;
	Vector2 gravitationalForce = Vector2(ax / entity->GetMass(), ay / entity->GetMass());

	return gravitationalForce;
}

float Body::GetRadius() {
	return radius;
}

void Body::SetOrbid(Body* orbitingPlanet, double distance) {
	this->orbitingPlanet = orbitingPlanet;
	this->position = orbitingPlanet->position;
	this->position.x += distance;


	double a = gravityConstant * (orbitingPlanet->GetMass() + mass);
	double b = a / GetDistance(orbitingPlanet->position);
	double vel = sqrt(b);
	SetVelocity(Vector2(0, vel));
}

std::string Body::GetName() {
	return name;
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}