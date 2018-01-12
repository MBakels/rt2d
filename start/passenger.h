/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file passenger.h
*
* @brief description of the Passenger behavior.
*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>

#include "body.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class Passenger {
public:
	/// @brief Constructor
	Passenger(Body* originPlanet);
	/// @brief Destructor
	virtual ~Passenger();

private:
	std::string destination;

	std::string GetDestination() { return destination; };

	void SetRandomDestination(Body* originPlanet);
};

#endif /* PASSENGER_H */