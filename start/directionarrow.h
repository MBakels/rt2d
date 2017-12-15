/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file directionarrow.h
*
* @brief description of the DirectionArrow behavior.
*/

#ifndef DIRECTIONARROW_H
#define DIRECTIONARROW_H

#include <rt2d/entity.h>

/// @brief The DirectionArrow class handels the arrow that points towards the middle of the system.
class DirectionArrow : public Entity {
public:
	/// @brief Constructor
	DirectionArrow(Entity* target);
	/// @brief Destructor
	virtual ~DirectionArrow();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Entity* target;
};

#endif /* DIRECTIONARROW_H */
