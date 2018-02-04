/**
 * Copyright 2015 Marco Bakels <marcobakels@live.nl>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "GameScene.h"
#include "menuscene.h"
#include "pausescene.h"
#include "gameoverscene.h"

std::vector<SuperScene*> scenes;
SuperScene* scene;
int running;

/// @brief main entry point
int main(void){
	// Core instance
	Core core;

	scenes.push_back(new MenuScene()); // Scene0
	scenes.push_back(new PauseScene()); // Scene1
	scenes.push_back(NULL); // Scene2
	scenes.push_back(new GameOverScene()); // Scene3

	scene = scenes[0];

	running = 1;
	while(running) {
		core.run(scene);
		int status = scene->GetStatus();
		if (status < 3) {
			scene->ResetStatus();
			scene = scenes[status];
		}else if(status == 3){
			int score = ((GameScene*)scenes[2])->GetScore();
			scene = scenes[3];
			((GameOverScene*)scene)->SetScore(score);
		}else if (status == 4) {
			scene->ResetStatus();
			delete scenes[2];
			scenes[2] = new GameScene();
			scene = scenes[2];
		} else if (status == 5) {
			running = 0;
		}
	}

	for (int i = 0; i < scenes.size(); i++) {
		delete scenes[i];
		scenes[i] = NULL;
	}
	scenes.clear();

	return 0;
}