#ifndef _WorldClass_
#define _WorldClass_

#include "ConnectionClass_Header.h"
#include "PlayerClass_Header.h"
#include "RoomClass_Header.h"

class World {

public:
	Room* places;
	Player character;
	World(Player player, Room* rooms);


};

void CreateWorld(World& barcelona);
#endif