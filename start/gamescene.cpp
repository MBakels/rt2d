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
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	addChild(spaceship);

	earth = new Planet("Earth", 3000.0f);
	earth->position = Point2(500, 400);
	addChild(earth);
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

	spaceship->AddForce(earth->GravitationalForce(spaceship));

	std::cout << ((Vector2)earth->GravitationalForce(spaceship)).getLength() << std::endl;
}
