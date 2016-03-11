#ifndef _GameFunctions_
#define _GameFunctions_

#include "WorldClass_Header.h"

void CreateWorld(World* barcelona);

void CleanWorld(World* barcelona);

void GameLoop(World* barcelona);

enum actions {
	north, south, east, west, quit, open_door, not_recognised
};

#endif