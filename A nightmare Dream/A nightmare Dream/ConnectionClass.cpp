#include "RoomClass_Header.h"

Room::Connection::Connection(){
	connected = false;
	closed = false;
	next_room = NULL;
	food_consumed = 1;
}

Room::Connection::Connection(bool is_connected, bool close_door, Room* following_room, int hungry_decrementor) : connected(is_connected), closed(close_door), next_room(following_room),
																										food_consumed(hungry_decrementor) {}

void Room::Connection::set_connection(bool is_connected, bool close_door, Room* following, int food){
	connected = is_connected;
	closed = close_door;
	next_room = following;
	food_consumed = food;
}

bool Room::Connection::get_connected() const {
	return connected;
}

bool Room::Connection::get_closed() const {
	return closed;
}

Room* Room::Connection::get_next_room() const{
	return next_room;
}

int Room::Connection::get_food_consumed() const{
	return food_consumed;
}