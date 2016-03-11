#ifndef _GameLogicFunctions_
#define _GameLogicFunctions_

#include "GameFunctions_Header.h"
#include "RoomClass_Header.h"
#include <iostream>

actions interpret_input(const std::string input); 

bool can_move(actions direction, Room* actual_room);

bool no_closed(actions direction, Room* next_room);

void look_room(Room* actual_room);

std::string open_connection(Room* actual_room);

bool is_a_direction(actions interpreted);

actions find_connection_direction(Room* actual_room, Room* next_room);

#endif