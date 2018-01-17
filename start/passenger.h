/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file passenger.h
*
* @brief description of the Passenger behavior.
*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <vector>

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class Passenger {
public:
	/// @brief Constructor
	Passenger(std::string originPlanetName);
	/// @brief Destructor
	virtual ~Passenger();

	std::string GetDestination() { return destination; };

private:
	std::string destination;

	void SetRandomDestination(std::string originPlanetName);
};

#endif /* PASSENGER_H */