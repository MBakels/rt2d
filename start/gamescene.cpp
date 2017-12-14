/**
 * This class describes the GameScene behavior.
 *
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 */

#include <fstream>
#include <sstream>

#include "gamescene.h"

GameScene::GameScene() : Scene(){
	spaceship = new SpaceShip();
	spaceship->position = Point2(1000, SHEIGHT / 2);
	spaceship->SetVelocity(Vector2(0, -130));
	addChild(spaceship);

	sun = new Body("sun", 100000.0f);
	sun->position = Point(SWIDTH / 2, SHEIGHT / 2);
	addChild(sun);
	solarSystem.push_back(sun);

	earth = new Body("Earth", 9000.0f);
	earth->SetOrbid(sun, 80, 80, -0.007, 0);
	addChild(earth);
	solarSystem.push_back(earth);

	mars = new Body("Mars", 40000.0f);
	mars->SetOrbid(sun, 200, 200, 0.005, 0);
	addChild(mars);
	solarSystem.push_back(mars);
}


GameScene::~GameScene(){
	this->removeChild(spaceship);

	delete spaceship;
}

void GameScene::update(float deltaTime){
	// ###############################################################
	// Escape key pauses game
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	for each (Body* planet in solarSystem) {
		spaceship->AddForce(planet->GravitationalForce(spaceship));
	}
}
