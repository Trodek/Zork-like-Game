#include <iostream>
#include "GameFunctions_Header.h"
#include "WorldClass_Header.h"
#include "MemLeaks.h"

int main(){

	ReportMemoryLeaks();
	
	World* Barcelona = new World;
	CreateWorld(Barcelona);
	GameLoop(Barcelona);
	CleanWorld(Barcelona);

	return 0;
}