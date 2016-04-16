#include "ClassEntity.h"
#include "ClassWorld.h"

World* Game = nullptr;

int main(){

	printf("Welcome to this shit.\n");

	Game = new World;
	bool end = false;
	
	while (!end){
		end = Game->Play();
	}

	delete Game;

	return 0;
}