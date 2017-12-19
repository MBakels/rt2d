/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file basicentity.h
*
* @brief description of the BasicEntity behavior.
*/

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <rt2d/entity.h>

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class BasicEntity : public Entity {
public:
	/// @brief Constructor
	BasicEntity();
	/// @brief Destructor
	virtual ~BasicEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
};

#endif /* BASICENTITY_H */