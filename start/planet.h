/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file planet.h
*
* @brief description of the Planet behavior.
*/

#ifndef PLANET_H
#define PLANET_H

#include <rt2d/entity.h>
#include "spaceship.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class Planet : public Entity {
public:
	/// @brief Constructor
	Planet(std::string name, float mass);
	/// @brief Destructor
	virtual ~Planet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	float GravitationalForce(SpaceShip* entity);

private:
	std::string planetName;
	float mass;
	float gravity;
};

#endif /* PLANET_H */