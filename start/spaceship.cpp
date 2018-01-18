/**
 * This class describes the SpaceShip behavior.
 *
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 */

#include "spaceship.h"

SpaceShip::SpaceShip() : SpaceEntity(){
	addSprite("assets/ship.tga");
	sprite()->size = Point(30, 30);
	rotationSpeed = 3.14f;
	velocity = Vector2(0, 0);
	polar = Polar((rand() % 360) * DEG_TO_RAD, 200.0f);
	mass = 1000.0f;
	maxPassengers = 30;
}

SpaceShip::~SpaceShip(){
	std::vector<Passenger*>::iterator passengersIt = passengers.begin();
	while (passengersIt != passengers.end()) {
		//delete (*passengersIt);
		passengersIt++;
	}
}

void SpaceShip::update(float deltaTime){
	// ###############################################################
	// Key input for spaceship
	// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		velocity += polar.cartesian() * deltaTime;
	}
	if (input()->getKey(KeyCode::A)) {
		polar.angle -= rotationSpeed * deltaTime;
	}
	if (input()->getKey(KeyCode::D)) {
		polar.angle += rotationSpeed * deltaTime;
	}

	rotation.z = polar.angle;
	position += velocity * deltaTime;
}

void SpaceShip::embarking(int numberOfPassengers, std::string originPlanetName) {
	for (int i = 0; i < numberOfPassengers; i++) {
		passengers.push_back(new Passenger(originPlanetName));
	}
}

int SpaceShip::disembarking(std::string planetName) {
	int disembarkingPassengers = 0;
	std::vector<Passenger*>::iterator PassengersIt = passengers.begin();
	while (PassengersIt != passengers.end()) {
		if ((*PassengersIt)->GetDestination() == planetName) {
			delete (*PassengersIt);
			PassengersIt = passengers.erase(PassengersIt);
			disembarkingPassengers++;
		} else {
			PassengersIt++;
		}		
	}
	return disembarkingPassengers;
}
