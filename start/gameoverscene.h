/**
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*
* @file gameoverscene.h
*
* @brief description of the GameOverScene behavior.
*/

#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

//#include <rt2d/scene.h>

#include "superscene.h"

/// @brief The SpaceShip class handels the spaceship movement and keeps a list of passengers.
class GameOverScene : public SuperScene {
public:
	/// @brief Constructor
	GameOverScene();
	/// @brief Destructor
	virtual ~GameOverScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
};

#endif /* GAMEOVERSCENE_H */