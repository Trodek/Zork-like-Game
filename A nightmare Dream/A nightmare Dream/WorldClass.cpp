#include "WorldClass_Header.h"
#include "RoomClass_Header.h"
#include "PlayerClass_Header.h"
#include "ConnectionClass_Header.h"
#include <iostream>

using namespace std;

World::World(){
	character = NULL;
	room_map = NULL;
}

World::World(Player* player, Map* bcn) : character(player), room_map(bcn){}

