#include "ConnectionClass_Header.h"
#include "RoomClass_Header.h"
#include <iostream>


Room::Room( std::string type, std::string info, Connection to_north, Connection to_south, Connection to_east, Connection to_west) : name(type), basic_description(info),
																																	north(to_north), south(to_south), 
																																	east(to_east), west(to_west){}

std::string Room::get_name() const {
	return name;
}

std::string Room::get_description() const{
	return basic_description;
}

Connection Room::get_north() const {
	return north;
}

Connection Room::get_south() const {
	return south;
}

Connection Room::get_east() const {
	return east;
}

Connection Room::get_west() const {
	return west;
}