#include <iostream>
#include <string>
#include "GameFunctions_Header.h"
#include "RoomClass_Header.h"

bool can_move(actions direction, Room* next_room){
	switch (direction){
		case north: return next_room->north.get_connected(); break;
		case east: return next_room->east.get_connected(); break;
		case west: return next_room->west.get_connected(); break;
		case south: return next_room->south.get_connected(); break;
	}
}

bool no_closed(actions direction, Room* next_room){
	return !(next_room->north.get_closed());
}