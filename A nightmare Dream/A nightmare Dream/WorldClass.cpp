#include "WorldClass_Header.h"
#include "RoomClass_Header.h"
#include "PlayerClass_Header.h"
#include "ConnectionClass_Header.h"
#include <iostream>

using namespace std;

World::World(Player player, Room* rooms) : character(player), places(rooms){}

void CreateWorld(World& barelona){

}