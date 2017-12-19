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
#include "directionarrow.h"

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

	void ApplieGravity();

	void SetupSolarSystem();

	void CreateHelpers();

private:
	/// @brief the spaceship controlled by the player.
	SpaceShip* spaceship;
	Body* currentOrbidShip;
	DirectionArrow* directionArrow;
	std::vector<Body*> solarSystem;
	bool helpersEnabled;
	Body* sun;
	Body* mercury;
	BasicEntity* mercuryOrbid;
	Body* venus;
	BasicEntity* venusOrbid;
	Body* earth;
	BasicEntity* earthOrbid;
	Body* mars;
	BasicEntity*marsOrbid;
	Body* jupiter;
	BasicEntity* jupiterOrbid;
	Body* saturn;
	BasicEntity*saturnOrbid;
	Body* uranus;
	BasicEntity* uranusOrbid;
	Body* neptune;
	BasicEntity* neptuneOrbid;
};

#endif /* GAMESCENE_H */
