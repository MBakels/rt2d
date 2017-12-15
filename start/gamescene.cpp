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
	spaceship->position = Point2(1000, 100);
	spaceship->SetVelocity(Vector2(0, -130));
	addChild(spaceship);

	SetupSolarSystem();

	directionArrow = new DirectionArrow(sun);
	addChild(directionArrow);
}


GameScene::~GameScene(){
	removeChild(spaceship);
	removeChild(sun);
	removeChild(mercury);
	removeChild(venus);
	removeChild(earth);
	removeChild(mars);

	delete spaceship;
	delete sun;
	delete mercury;
	delete venus;
	delete earth;
	delete mars;
}

void GameScene::update(float deltaTime){
	// ###############################################################
	// Escape key pauses game
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	
	camera()->position.x = spaceship->position.x;
	camera()->position.y = spaceship->position.y;

	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);

	Point2 directionArrow_pos = Point2(cam_pos.x, cam_pos.y - 50 + SHEIGHT / 2);
	directionArrow->position = directionArrow_pos;

	ApplieGravity();
}

void GameScene::ApplieGravity() {
	std::vector<Body*> inGravityField;
	for each(Body* planet in solarSystem) {
		if (planet->GravitationalForce(spaceship).getLength() >= 0.3f && planet != sun) {
			inGravityField.push_back(planet);
		}
	}

	if (inGravityField.size() != 0) {
		Vector2 strongetsGravity = inGravityField[0]->GravitationalForce(spaceship);
		for (int i = 1; i < inGravityField.size(); i++) {
			if (inGravityField[i]->GravitationalForce(spaceship) > strongetsGravity) {
				strongetsGravity = inGravityField[i]->GravitationalForce(spaceship);
			}
		}
		spaceship->AddForce(strongetsGravity);
	} else {
		spaceship->AddForce(sun->GravitationalForce(spaceship));
	}
}

void GameScene::SetupSolarSystem() {
	sun = new Body("Sun", 300000.0f);
	sun->position = Point(SWIDTH / 2, SHEIGHT / 2);
	addChild(sun);
	solarSystem.push_back(sun);

	mercury = new Body("Mercury", 30000.0f);
	mercury->SetOrbid(sun, 80, 80, 0.01, PI * 0.9);
	addChild(mercury);
	solarSystem.push_back(mercury);

	venus = new Body("venus", 45000.0f);
	venus->SetOrbid(sun, 130, 130, 0.009, PI * 0.5);
	addChild(venus);
	solarSystem.push_back(venus);

	earth = new Body("Earth", 60000.0f);
	earth->SetOrbid(sun, 190, 190, 0.008, PI * 1);
	addChild(earth);
	solarSystem.push_back(earth);

	mars = new Body("Mars", 36000.0f);
	mars->SetOrbid(sun, 240, 240, 0.007, PI * 1.6);
	addChild(mars);
	solarSystem.push_back(mars);
}
