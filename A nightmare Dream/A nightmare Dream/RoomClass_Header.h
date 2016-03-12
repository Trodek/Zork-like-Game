#ifndef _RoomClass_
#define _RoomClass_

#include <iostream>

class Room;


class Connection{

	bool connected;
	bool closed;
	bool can_be_closed;
	Room* next_room;
	int food_consumed;

public:

	Connection();
	Connection(bool is_connected, bool close_door, bool can_closed, Room* following_room, int hungry_decrementor);
	void set_connection(bool is_connected, bool close_door, bool can_close, Room* following, int food);
	bool get_connected() const;
	bool get_closed() const;
	bool get_can_close() const;
	Room* get_next_room() const;
	int get_food_consumed() const;
	void open_door();
	void close_door();
};

class Room {

	std::string name;
	std::string basic_description;
	

public:
	
	Connection north;
	Connection south;
	Connection east;
	Connection west;

	Room();
	Room(const std::string& type, const std::string& info);
	std::string get_name() const;
	std::string get_description() const;
	

};

#endif