/**
* This class describes the Planet behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "body.h"

Body::Body(std::string name, float mass, float diameter, int scoreValue, std::string filePath) : SpaceEntity() {
	gravityConstant = 6.6742e-11;
	this->name = name;
	this->mass = mass;
	this->diameter = diameter;
	addSprite(filePath);
	sprite()->size = Point(diameter, diameter);
	stationOrbit = NULL;
	stationOrbitHeight = 0;
	stableOrbitTimer = 5;
	passengersWaiting = (rand() % 5) + 2;
	this->scoreValue = scoreValue;
}

Body::~Body() {
	removeChild(stationOrbit);
	delete stationOrbit;
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

void Body::SetOrbit(Point3 orbitingPlanetPosition, float orbitingPlanetMass, float distance) {
	this->position = orbitingPlanetPosition;
	this->position.x += distance;

	float a = gravityConstant * (orbitingPlanetMass + mass);
	float b = a / distance;
	float vel = sqrt(b);
	SetVelocity(Vector2(0, vel));
}

void Body::SetStationOrbit(float height) {
	stationOrbitHeight = height;
	Line* circle = new Line();
	circle->createCircle(height, 30);
	stationOrbit = new BasicEntity();
	stationOrbit->addLine(circle);
	stationOrbit->line()->color = BLUE;
	addChild(stationOrbit);
	delete circle;
}

float Body::GetDistance(Point3 otherPos) {
	return sqrt(pow((position.x - otherPos.x), 2) + pow((position.y - otherPos.y), 2));
}

bool Body::CheckStableOrbit(Point3 shipPosition, float deltaTime) {
	float minHeight = stationOrbitHeight - 30;
	float maxHeight = stationOrbitHeight + 30;
	float distance = GetDistance(shipPosition);
	if (distance >= minHeight && distance <= maxHeight) {
		stableOrbitTimer -= 1 * deltaTime;
		//std::cout << stableOrbitTimer << std::endl;
		if (stableOrbitTimer <= 0) {
			std::cout << "Resupplied" << std::endl;
			return true;
		}
	} else {
		stableOrbitTimer = 1;
	}
	return false;
}

bool Body::CheckCollision(Point3 otherPosition, float otherRadius) {
	float distance = GetDistance(otherPosition);
	float radius = diameter / 2;
	if (distance < radius + otherRadius) {
		return true;
	}
	return false;
}

