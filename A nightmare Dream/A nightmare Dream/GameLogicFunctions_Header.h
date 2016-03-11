#ifndef _GameLogicFunctions_
#define _GameLogicFunctions_

#include "GameFunctions_Header.h"
#include "RoomClass_Header.h"

bool can_move(actions direction, Room* next_room);

bool no_closed(actions direction, Room* next_room);

#endif