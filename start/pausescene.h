/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file pausescene.h
*
* @brief description of the PauseScene behavior.
*/

#ifndef PAUSESCENE_H
#define PAUSESCENE_H

//#include <rt2d/scene.h>

#include "superscene.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class PauseScene : public SuperScene {
public:
	/// @brief Constructor
	PauseScene();
	/// @brief Destructor
	virtual ~PauseScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
};

#endif /* PAUSESCENE_H */