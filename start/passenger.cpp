/**
* This class describes the Passenger behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "passenger.h"

Passenger::Passenger(Body* originPlanet) {
	SetRandomDestination(originPlanet);
}

Passenger::~Passenger() {

}

void Passenger::SetRandomDestination(Body* originPlanet) {
	std::string planetList[] = {"Mercury", "Venus", "Earth", "Mars"};
	do {
		int randomNumber = rand() % planetList->length();
		destination = planetList[randomNumber];
	} while (destination == originPlanet->GetName());
}
