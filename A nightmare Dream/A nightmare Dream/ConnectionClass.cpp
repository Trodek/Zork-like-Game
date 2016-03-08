#include "ConnectionClass_Header.h"

Connection::Connection(bool is_connected,bool close_door, int following_room, int hungry_decrementor) : connected(is_connected), closed(close_door) ,next_room(following_room), 
																										food_consumed(hungry_decrementor) {}

bool Connection::get_connected() const {
	return connected;
}

int Connection::get_next_room() const{
	return next_room;
}

int Connection::get_food_consumed() const{
	return food_consumed;
}