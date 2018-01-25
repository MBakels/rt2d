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
#include <rt2d/text.h>

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

private:
	/// @brief the spaceship controlled by the player.
	SpaceShip* spaceship;
	Body* currentOrbitShip;
	Body* lastResuppliedPlanet;
	DirectionArrow* directionArrow;
	std::vector<Body*> solarSystem;
	std::vector<BasicEntity*> helpers;
	bool helpersEnabled;
	Body* sun;
	Body* mercury;
	Body* venus;
	Body* earth;
	Body* mars;
	Body* jupiter;
	Body* saturn;
	Body* uranus;
	Body* neptune;
	Text* scoreText;
	int score;
	Text* passengersCounterText;
	Text* shipThrustPowerText;

	void SetupSolarSystem();

	void CreateHelpers();

	void Resupply();

	void CreateUI();

	void UpdateUI();

	void AddScore(int toAdd);

	void UpdatePassengersText();
};

#endif /* GAMESCENE_H */
