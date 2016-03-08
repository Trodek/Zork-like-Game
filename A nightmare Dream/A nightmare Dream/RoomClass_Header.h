#ifndef _RoomClass_
#define _RoomClass_

#include "ConnectionClass_Header.h"
#include <iostream>

class Room {

	std::string name;
	std::string basic_description;
	Connection north;
	Connection south;
	Connection east;
	Connection west;

public:
	Room(std::string type, std::string info, Connection to_north, Connection to_south, Connection to_east, Connection to_west);
	std::string get_name() const;
	std::string get_description() const;
	Connection get_north() const;
	Connection get_south() const;
	Connection get_east() const;
	Connection get_west() const;
	

};

#endif