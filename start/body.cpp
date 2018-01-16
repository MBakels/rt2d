/**
* This class describes the Planet behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "body.h"

Body::Body(std::string name, float mass, float diameter) : SpaceEntity() {
	gravityConstant = 6.6742e-11;
	this->name = name;
	this->mass = mass;
	this->diameter = diameter;
	addSprite("assets/planet.tga");
	sprite()->size = Point(diameter, diameter);
	stationOrbid = NULL;
	stationOrbidHeight = 0;
	stableOrbidTimer = 5;
	passengers = (rand() % 5) + 2;
}

Body::~Body() {
	removeChild(stationOrbid);
	delete stationOrbid;
}

void Body::update(float deltaTime) {
	this->position += this->velocity * deltaTime;
}

Vector2 Body::GravitationalForce(SpaceEntity* entity) {
	float dx = position.x - entity->position.x;
	float dy = position.y - entity->position.y;
	float distSQ = dx * dx + dy * dy;
	float dist = sqrt(distSQ);
	float force = (gravityConstant * ((mass + entity->GetMass()) / (dist*dist)));
	float ax = (force * dx) / dist;
	float ay = (force * dy) / dist;
	Vector2 gravitationalForce = Vector2(ax, ay);

	return gravitationalForce;
}

float Body::GetDiameter() {
	return diameter;
}

void Body::SetOrbid(Point3 orbitingPlanetPosition, float orbitingPlanetMass, float distance) {
	this->position = orbitingPlanetPosition;
	this->position.x += distance;

	float a = gravityConstant * (orbitingPlanetMass + mass);
	float b = a / distance;
	float vel = sqrt(b);
	SetVelocity(Vector2(0, vel));
}

void Body::SetStationOrbid(float height) {
	stationOrbidHeight = height;
	Line* circle = new Line();
	circle->createCircle(height, 30);
	stationOrbid = new BasicEntity();
	stationOrbid->addLine(circle);
	stationOrbid->line()->color = BLUE;
	addChild(stationOrbid);
	delete circle;
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}

bool Body::CheckStableOrbid(Point3 shipPosition, float deltaTime) {
	float minHeight = stationOrbidHeight - 30;
	float maxHeight = stationOrbidHeight + 30;
	float distance = GetDistance(shipPosition);
	if (distance >= minHeight && distance <= maxHeight) {
		stableOrbidTimer -= 1 * deltaTime;
		std::cout << stableOrbidTimer << std::endl;
		if (stableOrbidTimer <= 0) {
			std::cout << "Resupplied" << std::endl;
			return true;
		}
	} else {
		stableOrbidTimer = 5;
	}
	return false;
}

