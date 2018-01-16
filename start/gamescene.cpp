/**
 * This class describes the GameScene behavior.
 *
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 */

#include <fstream>
#include <sstream>

#include "gamescene.h"

GameScene::GameScene() : Scene(){
	srand(time(NULL));

	currentOrbidShip = NULL;
	lastResuppliedPlanet = NULL;
	helpersEnabled = true;

	spaceship = new SpaceShip();
	spaceship->position = Point2(800, 0);
	spaceship->SetVelocity(Vector2(0, 340));
	addChild(spaceship);

	SetupSolarSystem();

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
	// ###############################################################
	// Debug key
	// ###############################################################
	if (input()->getKeyUp(KeyCode::I)) {
		//std::cout << spaceship->GetPassengerAmount() << std::endl;
	}

	camera()->position.x = spaceship->position.x;
	camera()->position.y = spaceship->position.y;
	
	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);

	Point2 directionArrow_pos = Point2(cam_pos.x, cam_pos.y - 50 + SHEIGHT / 2);
	directionArrow->position = directionArrow_pos;
	
	for each(Body* planet in solarSystem) {
		if (planet != sun) {
			planet->AddForce((sun->GravitationalForce(planet) * deltaTime));
			//std::cout << "Sun force on " << planet->GetName() << ":    " << sun->GravitationalForce(planet).getLength() << std::endl;
		}
		if (planet->GravitationalForce(spaceship).getLength() >= 10.0f && planet != sun) {
			spaceship->AddForce(planet->GravitationalForce(spaceship) * deltaTime);
			if (planet != lastResuppliedPlanet) {
				bool stableOrbid = planet->CheckStableOrbid(spaceship, deltaTime);
				if (stableOrbid) {
					lastResuppliedPlanet = planet;
				}
			}
			//std::cout << planet->GetName() << "    " << planet->GravitationalForce(spaceship).getLength() << std::endl;
		}
	}
	spaceship->AddForce(sun->GravitationalForce(spaceship) * deltaTime);
}

void GameScene::SetupSolarSystem() {
	sun = new Body("Sun", 1988500e24 / 2000000000000, 300); // 1988500e24    1391400
	this->addChild(sun);
	solarSystem.push_back(sun);
	
	mercury = new Body("Mercury", 0.33011e24 / 150000000, 4879 / 100); // 0.33011e24    4879
	mercury->SetOrbid(sun, 57.91e6 / 100000); // 57.91e6
	mercury->SetStationOrbid(100);
	solarSystem.push_back(mercury);

	venus = new Body("Venus", 4.8675e24 / 150000000, 12104 / 100); // 4.8675e24    12104
	venus->SetOrbid(sun, 108.21e6 / 100000); // 108.21e6
	venus->SetStationOrbid(100);
	solarSystem.push_back(venus);
	
	earth = new Body("Earth", 5.97237e24 / 150000000, 12756 / 100); // 5.97237e24    12756
	earth->SetOrbid(sun, 149.60e6 / 100000); // 149.60e6
	earth->SetStationOrbid(100);
	solarSystem.push_back(earth);
	
	mars = new Body("Mars", 0.64171e24 / 150000000, 6792 / 100); // 0.64171e24    6792
	mars->SetOrbid(sun, 227.92e6 / 100000); // 227.92e6
	mars->SetStationOrbid(100);
	solarSystem.push_back(mars);
	
	if (helpersEnabled) {
		CreateHelpers();
	}

	this->addChild(mercury);
	this->addChild(venus);
	this->addChild(earth);
	this->addChild(mars);
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
		this->addChild(helper);
		delete circle;
	}
}
