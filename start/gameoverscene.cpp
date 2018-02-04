/**
* This class describes the BasicEntity behavior.
*
* Copyright 2015 Marco Bakels <marcobakels@live.nl>
*/

#include "gameoverscene.h"

GameOverScene::GameOverScene() : SuperScene() {
	background = new BasicEntity();
	background->position = Point(SWIDTH / 2, SHEIGHT / 2);
	background->addSprite("assets/star_background.tga");
	background->sprite()->size = Point2(SWIDTH, SWIDTH);
	addChild(background);

	toMenuButton = new BasicEntity();
	Sprite* startButtonSpr = new Sprite();
	toMenuButton->addSprite(startButtonSpr);
	delete startButtonSpr;
	toMenuButton->position = Point(SWIDTH / 2, SHEIGHT / 2 + 200);
	toMenuButton->sprite()->color = RGBAColor(0, 0, 0, 220);
	toMenuButton->sprite()->size = Point2(300, 100);
	toMenuButtonText = new Text();
	toMenuButtonText->message("To menu");
	toMenuButtonText->position.x -= 95;
	toMenuButton->addChild(toMenuButtonText);
	addChild(toMenuButton);

	gameOverText = new Text();
	gameOverText->message("GAME OVER");
	gameOverText->scale = Point(2, 2);
	gameOverText->position = Point(SWIDTH / 2 - 250, SHEIGHT / 2 - 200);
	this->addChild(gameOverText);

	scoreText = new Text();
	scoreText->message("Score: ");
	scoreText->position = Point(SWIDTH / 2 - 110, SHEIGHT / 2);
	this->addChild(scoreText);
}

GameOverScene::~GameOverScene() {
	removeChild(background);
	delete background;

	removeChild(toMenuButton);
	delete toMenuButton;
	removeChild(toMenuButtonText);
	delete toMenuButtonText;
}

void GameOverScene::update(float deltaTime) {
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();
	if (input()->getMouseDown(0)) {
		if (mouseX > toMenuButton->position.x - toMenuButton->sprite()->size.x / 2 &&
			mouseX < toMenuButton->position.x + toMenuButton->sprite()->size.x / 2 &&
			mouseY > toMenuButton->position.y - toMenuButton->sprite()->size.y / 2 &&
			mouseY < toMenuButton->position.y + toMenuButton->sprite()->size.y / 2) {
			status = 0;
		}
	}
}

void GameOverScene::SetScore(int score) {
	scoreText->message("Score:" + std::to_string(score));
}