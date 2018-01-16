/**
* This class describes the Passenger behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "passenger.h"

Passenger::Passenger(std::string originPlanetName) {
	SetRandomDestination(originPlanetName);
}

Passenger::~Passenger() {

}

void Passenger::SetRandomDestination(std::string originPlanetName) {
	std::string planetList[] = {"Mercury", "Venus", "Earth", "Mars"};
	do {
		int randomNumber = rand() % planetList->length();
		destination = planetList[randomNumber];
	} while (destination == originPlanetName);
}
