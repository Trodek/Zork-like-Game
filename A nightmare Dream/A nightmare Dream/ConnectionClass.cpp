#include "RoomClass_Header.h"

Connection::Connection(){
	connected = false;
	closed = false;
	next_room = NULL;
	food_consumed = 1;
}

Connection::Connection(bool is_connected, bool close_door, bool can_close, Room* following_room, int hungry_decrementor) : connected(is_connected), closed(close_door), can_be_closed(can_close), next_room(following_room),
																										food_consumed(hungry_decrementor) {}

void Connection::set_connection(bool is_connected, bool close_door, bool can_close, Room* following, int food){
	connected = is_connected;
	closed = close_door;
	can_be_closed = can_close;
	next_room = following;
	food_consumed = food;
}

bool Connection::get_connected() const {
	return connected;
}

bool Connection::get_closed() const {
	return closed;
}

bool Connection::get_can_close() const {
	return can_be_closed;
}

Room* Connection::get_next_room() const{
	return next_room;
}

int Connection::get_food_consumed() const{
	return food_consumed;
}

void Connection::open_door(){
	closed = false;
}

void Connection::close_door(){
	closed = true;
}