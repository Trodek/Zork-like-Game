#ifndef _ConnectionsClass_
#define _ConnectionsClass_

class Connection{

	bool connected;
	bool closed;
	int next_room;
	int food_consumed;

public:
	Connection(bool is_connected, bool close_door, int following_room, int hungry_decrementor); 
	bool get_connected() const;
	int get_next_room() const;
	int get_food_consumed() const;
};

#endif