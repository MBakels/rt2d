/**
 * This class describes the GameScene behavior.
 *
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 */

#include <fstream>
#include <sstream>

#include "gamescene.h"

GameScene::GameScene() : Scene(){
	currentOrbidShip = NULL;
	helpersEnabled = true;

	SetupSolarSystem();

	spaceship = new SpaceShip();
	spaceship->position = Point2(800, 200);
	spaceship->SetVelocity(Vector2(0, -130));
	addChild(spaceship);

	directionArrow = new DirectionArrow(sun);
	addChild(directionArrow);
}


GameScene::~GameScene(){
	
	removeChild(spaceship);
	delete spaceship;

	removeChild(directionArrow);
	delete directionArrow;
	
	std::vector<Body*>::iterator solarSystemIt = solarSystem.begin();
	while (solarSystemIt != solarSystem.end()) {
		removeChild((*solarSystemIt));
		delete (*solarSystemIt);
		solarSystemIt++;
	}

	std::vector<BasicEntity*>::iterator helpersIt = helpers.begin();
	while (helpersIt != helpers.end()) {
		removeChild((*helpersIt));
		delete (*helpersIt);
		helpersIt++;
	}
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
		currentOrbidShip = inGravityField[0];
		for (int i = 1; i < inGravityField.size(); i++) {
			if (inGravityField[i]->GravitationalForce(spaceship) > strongetsGravity) {
				strongetsGravity = inGravityField[i]->GravitationalForce(spaceship);
				currentOrbidShip = inGravityField[i];
			}
		}
		spaceship->AddForce(strongetsGravity);
		if (currentOrbidShip->GravitationalForce(spaceship).getLength() >= 0.5f) {
			float slowDown = (0.8f / currentOrbidShip->GravitationalForce(spaceship).getLength()) - 1.6f;
			if (slowDown > 1) { slowDown = 1; }
			if (slowDown < 0) { slowDown = 0; }
			SlowDownPlanets(slowDown);
		}
		
		//std::cout << strongetsGravity.getLength() << std::endl;
		
	} else {
		spaceship->AddForce(sun->GravitationalForce(spaceship));
		currentOrbidShip = NULL;
	}
}

void GameScene::SetupSolarSystem() {
	sun = new Body("Sun", 400000.0f, 300.0f);
	addChild(sun);
	solarSystem.push_back(sun);

	mercury = new Body("Mercury", 30000.0f, 32.53f);
	mercury->SetOrbid(sun, 386, 0.09, PI * 0.9);
	solarSystem.push_back(mercury);

	venus = new Body("venus", 45000.0f, 80.69f);
	venus->SetOrbid(sun, 721.33, 0.08, PI * 0.5);
	solarSystem.push_back(venus);

	earth = new Body("Earth", 60000.0f, 85.04f);
	earth->SetOrbid(sun, 997.33, 0.07, PI * 1.2);
	solarSystem.push_back(earth);

	mars = new Body("Mars", 36000.0f, 45.28f);
	mars->SetOrbid(sun, 1519.33, 0.06, PI * 1.6);
	solarSystem.push_back(mars);

	if (helpersEnabled) {
		CreateHelpers();
	}

	addChild(mercury);
	addChild(venus);
	addChild(earth);
	addChild(mars);
}

void GameScene::CreateHelpers() {
	for each(Body* planet in solarSystem) {
		Line* circle = new Line();
		circle->createCircle(planet->GetDistance(Vector2(0, 0)), 100);
		BasicEntity* helper = new BasicEntity();
		helper->addLine(circle);
		helper->line()->color = GRAY;
		helper->position = Point2(0, 0);
		helpers.push_back(helper);
		addChild(helper);
		delete circle;
	}
}

void GameScene::SlowDownPlanets(float amount) {
	for each(Body* planet in solarSystem) {
		planet->SetSlowDown(amount);
	}
}
