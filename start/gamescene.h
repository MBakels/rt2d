/**
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 *
 * @file gamescene.h
 *
 * @brief description of the GameScene behavior.
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <rt2d/scene.h>

#include "spaceship.h"
#include "body.h"

/// @brief The MyScene class is the Scene implementation.
class GameScene : public Scene{
public:
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the spaceship controlled by the player.
	SpaceShip* spaceship;
	std::vector<Body*> solarSystem;
	Body* sun;
	Body* earth;
	Body* mars;
};

#endif /* GAMESCENE_H */
