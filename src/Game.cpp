/*
 * Game.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: Nathan Hughes
 */




#include "headers/Game.hpp"
#include <iostream>
#include <sstream>


Game::Game():
g_Window(sf::VideoMode(640, 640), "SFML"),
g_Sounds(),
g_AlexandriaFont(),
FRAMES_PER_SECOND(60),
TIME_PER_FRAME(sf::seconds(1.f/FRAMES_PER_SECOND)),
g_Fps(),
g_FpsTimer(),
g_FpsNumFrames(),
g_GameState(0),
g_SplashScreenTexture(),
g_SplashScreenSprite(),
g_BackgroundSprite(),
g_BackgroundTexture(),
g_Map(),
g_player(sf::Vector2f(10,10), 64.f),
g_scoreText(),
g_score(0)
{
	//setting window properties
	g_Window.setVerticalSyncEnabled(true);
	g_Window.setFramerateLimit((unsigned int) FRAMES_PER_SECOND);


	//setting font location
	g_AlexandriaFont.loadFromFile("fonts/AlexandriaFLF.ttf");

	//loading splash screen
	g_SplashScreenTexture.loadFromFile("images/intro.png");
	g_SplashScreenSprite.setTexture(g_SplashScreenTexture);
	g_SplashScreenSprite.setPosition(0.f,0.f);

	//setting g_Fps info
	g_Fps.setCharacterSize(20);
	g_Fps.setFont(g_AlexandriaFont);
	g_Fps.setPosition(0,0);

	//setting the score info
	g_scoreText.setFont(g_AlexandriaFont);
	g_scoreText.setPosition(220,150);
	g_scoreText.setScale(10,10);
	g_scoreText.setString("0");


	//Set up some of the finner details of the game
    setUpMap();
	setUpPlayerMovements();

    //Perform some sound loading
    //TODO formalize and make nice to work with
    g_Sounds.addTrack("music/starterTheme.wav");

	/* initialize random seed: */
	srand ((unsigned int) time(NULL));

}


void Game::run(){



	//clocks and times used to get custom game loop working
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//setting g_GameState to be intro on run
	g_GameState = 0;

			//main loop to run the entire length of games
			//life
	        while (g_Window.isOpen()) {
	            sf::Time dt = clock.restart();
	            timeSinceLastUpdate += dt;


	            while(timeSinceLastUpdate > TIME_PER_FRAME) {

	            	timeSinceLastUpdate -= TIME_PER_FRAME;
	                processEvents();
	                update(dt);
	            }
	            updateFPSCounter(dt);
                playSounds();
	            render();
	        }
}



//process input events
void Game::processEvents(){

	sf::Event event;

	while(g_Window.pollEvent(event)){


			if(event.type == sf::Event::Closed)
				g_Window.close();


			if(g_GameState == INTRO){
				if(event.key.code == sf::Keyboard::Space){
					g_GameState = PLAYING;
				}
			}

            if(g_GameState == PLAYING){

				//Handle a key being pressed
                if(event.type == sf::Event::KeyPressed){
	                g_player.handlePlayerInput(event.key.code, true);
				}

			}

		}

}

//perform logic and call for collision checks
void Game::update(sf::Time elapsedTime){


	handleCollisions();
	g_player.updateCharacter(elapsedTime);


}


//Put all the collision checking and handling here
void Game::handleCollisions(){

		/*
		 * TODO: Add some
		 */

    }


void Game::updateFPSCounter(sf::Time dt){

	g_FpsTimer += dt;
	g_FpsNumFrames += 1;

	if( g_FpsTimer >= sf::seconds(1.0f)){

		std::ostringstream ss;

		ss << g_FpsNumFrames;
		g_Fps.setString(ss.str());

		g_FpsTimer -= sf::seconds(1.0f);
		g_FpsNumFrames = 0;
	}

}

//re-apply changes to window
void Game::render(){

	//wipe window clear
	g_Window.clear(sf::Color::Black);

	switch (g_GameState) {
		case INTRO:
			//draw splash screen
			g_Window.draw(g_SplashScreenSprite);
			break;
		case PLAYING:
			g_Window.draw(g_Map);
			g_Window.draw(g_player);
			break;
		default:
			break;
	}

	//display new screen layout
	g_Window.draw(g_Fps);
	g_Window.display();


}


void Game::playSounds() {
    switch (g_GameState){

        case PLAYING:
            g_Sounds.playBackgroundMusic();
            break;
        default:
            break;

    }
}

void Game::setUpPlayerMovements() {


	//setup the player
	std::string character = "images/char.png";


	std::vector<sf::Vector2f> leftMovements, rightMovements, downMovements, upMovements;

	leftMovements.push_back(sf::Vector2f(0, 62));
	leftMovements.push_back(sf::Vector2f(62, 62));
	leftMovements.push_back(sf::Vector2f(124, 62));
	leftMovements.push_back(sf::Vector2f(186, 62));

	rightMovements.push_back(sf::Vector2f(0, 124));
	rightMovements.push_back(sf::Vector2f(62, 124));
	rightMovements.push_back(sf::Vector2f(124, 124));
	rightMovements.push_back(sf::Vector2f(186, 124));

	upMovements.push_back(sf::Vector2f(0, 186));
	upMovements.push_back(sf::Vector2f(62, 186));
	upMovements.push_back(sf::Vector2f(124, 186));
	upMovements.push_back(sf::Vector2f(186, 186));

	downMovements.push_back(sf::Vector2f(0, 0));
	downMovements.push_back(sf::Vector2f(62, 0));
	downMovements.push_back(sf::Vector2f(124, 0));
	downMovements.push_back(sf::Vector2f(186, 0));

	g_player.setUp(character,62, 62, leftMovements, rightMovements, upMovements, downMovements);


}

void Game::setUpMap() {

    std::vector<int> myVec;

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
            myVec.push_back(44);
        }

    }

    //10x10
    g_Map.load(myVec, 10, 10, "images/spriteSheet.png");


}











