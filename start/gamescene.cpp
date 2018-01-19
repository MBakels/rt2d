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
	score = 0;

	spaceship = new SpaceShip();
	spaceship->position = Point2(1350, 0);
	spaceship->SetVelocity(Vector2(0, 370));
	addChild(spaceship);

	SetupSolarSystem();

	CreateUI();
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
	solarSystem.clear();

	std::vector<BasicEntity*>::iterator helpersIt = helpers.begin();
	while (helpersIt != helpers.end()) {
		removeChild((*helpersIt));
		delete (*helpersIt);
		helpersIt++;
	}
	helpers.clear();
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
		std::cout << spaceship->GetPassengerAmount() << std::endl;
	}

	for each(Body* planet in solarSystem) {
		if (planet != sun) {
			planet->AddForce((sun->GravitationalForce(planet) * deltaTime));
			//std::cout << "Sun force on " << planet->GetName() << ":    " << sun->GravitationalForce(planet).getLength() << std::endl;
		}
		if (planet->GravitationalForce(spaceship).getLength() >= 10.0f && planet != sun) {
			spaceship->AddForce(planet->GravitationalForce(spaceship) * deltaTime);
			if (planet != lastResuppliedPlanet) {
				bool stableOrbid = planet->CheckStableOrbid(spaceship->position, deltaTime);
				if (stableOrbid) {
					lastResuppliedPlanet = planet;
					Resupply();
				}
			}
			//std::cout << planet->GetName() << "    " << planet->GravitationalForce(spaceship).getLength() << std::endl;
		}
	}
	spaceship->AddForce(sun->GravitationalForce(spaceship) * deltaTime);

	camera()->position.x = spaceship->position.x;
	camera()->position.y = spaceship->position.y;

	for each(Body* planet in solarSystem) {
		if (planet->CheckCollision(spaceship->position, spaceship->GetRadius())) {
			std::cout << "collision with: " << planet->GetName() << std::endl;
		}
	}

	UpdateUI();
}

void GameScene::SetupSolarSystem() {
	sun = new Body("Sun", 1988500e24 / 1500000000000, 300, 0); // 1988500e24    1391400
	this->addChild(sun);
	solarSystem.push_back(sun);
	
	mercury = new Body("Mercury", 0.33011e24 / 100000000, 4879 / 50, 1); // 0.33011e24    4879
	mercury->SetOrbid(sun->position, sun->GetMass(), 57.91e6 / 70000); // 57.91e6
	mercury->SetStationOrbid(100);
	solarSystem.push_back(mercury);

	venus = new Body("Venus", 4.8675e24 / 100000000, 12104 / 50, 2); // 4.8675e24    12104
	venus->SetOrbid(sun->position, sun->GetMass(), 108.21e6 / 70000); // 108.21e6
	venus->SetStationOrbid(180);
	solarSystem.push_back(venus);
	
	earth = new Body("Earth", 5.97237e24 / 100000000, 12756 / 50, 3); // 5.97237e24    12756
	earth->SetOrbid(sun->position, sun->GetMass(), 149.60e6 / 70000); // 149.60e6
	earth->SetStationOrbid(200);
	solarSystem.push_back(earth);
	
	mars = new Body("Mars", 0.64171e24 / 100000000, 6792 / 50, 4); // 0.64171e24    6792
	mars->SetOrbid(sun->position, sun->GetMass(), 227.92e6 / 70000); // 227.92e6
	mars->SetStationOrbid(120);
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

void GameScene::Resupply() {
	int disembarkingPassengers = spaceship->disembarking(lastResuppliedPlanet->GetName());
	int scoreToAdd = disembarkingPassengers * lastResuppliedPlanet->GetScoreValue();
	AddScore(scoreToAdd);

	int passengersOnCurrentPlanet = lastResuppliedPlanet->GetPassengersWaiting();
	int shipCurrentPassengers = spaceship->GetPassengerAmount();
	int shipMaxPassengers = spaceship->GetMaxPassengers();
	if (shipCurrentPassengers < shipMaxPassengers) {
		int freeSpace = shipMaxPassengers - shipCurrentPassengers;
		if (passengersOnCurrentPlanet >= freeSpace) {
			lastResuppliedPlanet->SetPassengersWaiting(lastResuppliedPlanet->GetPassengersWaiting() - freeSpace);
			spaceship->embarking(freeSpace, lastResuppliedPlanet->GetName());
		} else {
			lastResuppliedPlanet->SetPassengersWaiting(0);
			spaceship->embarking(passengersOnCurrentPlanet, lastResuppliedPlanet->GetName());
		}
	}
	UpdatePassengersText();
}

void GameScene::CreateUI() {
	directionArrow = new DirectionArrow(sun);
	addChild(directionArrow);

	scoreText = new Text();
	scoreText->scale = Point2(0.5f, 0.5f);
	this->addChild(scoreText);
	scoreText->message("Score: 0");

	passengersCounterText = new Text();
	passengersCounterText->scale = Point2(0.5f, 0.5f);
	this->addChild(passengersCounterText);
	passengersCounterText->message("0 Passengers");

	shipThrustPowerText = new Text();
	shipThrustPowerText->scale = Point2(0.5f, 0.5f);
	this->addChild(shipThrustPowerText);
	shipThrustPowerText->message("ThrustPower: 0");
}

void GameScene::UpdateUI() {
	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);

	Point2 directionArrow_pos = Point2(cam_pos.x, cam_pos.y - 50 + SHEIGHT / 2);
	directionArrow->position = directionArrow_pos;

	scoreText->position = Point2(cam_pos.x + 50 - SWIDTH / 2, cam_pos.y + 50 - SHEIGHT / 2);
	passengersCounterText->position = Point2(cam_pos.x + 50 - SWIDTH / 2, cam_pos.y + 80 - SHEIGHT / 2);
	shipThrustPowerText->position = Point2(cam_pos.x + 50 - SWIDTH / 2, cam_pos.y + 110 - SHEIGHT / 2);

	shipThrustPowerText->message("ThrustPower: " + std::to_string(spaceship->GetThrustPower()));
}

void GameScene::AddScore(int toAdd) {
	score += toAdd;
	scoreText->message("Score:" + std::to_string(score));
}

void GameScene::UpdatePassengersText() {
	passengersCounterText->message(std::to_string(spaceship->GetPassengerAmount()) + " Passengers");
}
