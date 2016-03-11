#ifndef _WorldClass_
#define _WorldClass_

#include "ConnectionClass_Header.h"
#include "PlayerClass_Header.h"
#include "MapClass_Header.h"

class World {

public:
	Map* room_map;
	Player* character;
	World();
	World(Player* player, Map* bcn);


};

#endif