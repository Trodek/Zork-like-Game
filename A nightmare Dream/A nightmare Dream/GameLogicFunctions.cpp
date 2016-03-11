#include <iostream>
#include <string>
#include "GameFunctions_Header.h"
#include "GameLogicFunctions_Header.h"
#include "RoomClass_Header.h"

using namespace std;

actions interpret_input(const string input){
	if (input == "n" || input == "north" || input == "go north") return north;
	else if (input == "s" || input == "south" || input == "go south") return south;
	else if (input == "e" || input == "east" || input == "go east") return east;
	else if (input == "w" || input == "west" || input == "go west") return west;
	else if (input == "q" || input == "quit" || input == "exit") return quit;
	else if (input == "open door" || input == "open") return open_door;
	else if (input == "look arround" || input == "look") return look_arround;
	return not_recognised;
}

bool can_move(actions direction, Room* actual_room){
	switch (direction){
		case north: return actual_room->north.get_connected(); break;
		case east: return actual_room->east.get_connected(); break;
		case west: return actual_room->west.get_connected(); break;
		case south: return actual_room->south.get_connected(); break;
	}
}

bool no_closed(actions direction, Room* actual_room){
	switch (direction){
	case north: return !(actual_room->north.get_closed()); break;
	case east: return !(actual_room->east.get_closed()); break;
	case west: return !(actual_room->west.get_closed()); break;
	case south: return !(actual_room->south.get_closed()); break;
	}
}

void look_room(Room* actual_room){
	cout << endl << "From here in the " << actual_room->get_name() << " I can move to:";
	if (can_move(north, actual_room)) {
		Room* next_room = actual_room->north.get_next_room();
		cout << " north("<<next_room->get_name()<<")";
	}
	if (can_move(east, actual_room)) {
		Room* next_room = actual_room->east.get_next_room(); 
		cout << " east(" << next_room->get_name() << ")";
	}
	if (can_move(west, actual_room)) {
			Room* next_room = actual_room->west.get_next_room();
			cout << " west(" << next_room->get_name() << ")";
	}
	if (can_move(south, actual_room)) {
			Room* next_room = actual_room->south.get_next_room(); 
			cout << " south(" << next_room->get_name() << ")";
	}
	cout << '.'<<endl;
}

string open_connection(Room* actual_room){
	cout << endl << ">>What door do you want to open? " << endl;
	string direction_input;
	getline(cin, direction_input);
	cout << endl;
	actions interpreted = interpret_input(direction_input);
	if (is_a_direction(interpreted)){
		if (can_move(interpreted, actual_room)){
			if (!(no_closed(interpreted, actual_room)))
			switch (interpreted){
				case north:{
							   Room* next_room = actual_room->north.get_next_room();
							   actual_room->north.open_door();
							   actions door_direction_next_room = find_connection_direction(actual_room, next_room);
							   switch (door_direction_next_room){
									case north: next_room->north.open_door(); break;
									case south:next_room->south.open_door(); break;
									case east:next_room->east.open_door(); break;
									case west:next_room->west.open_door(); break;
							   }
							}
							break;
				case south:{
							   Room* next_room = actual_room->south.get_next_room();
							   actual_room->south.open_door();
							   actions door_direction_next_room = find_connection_direction(actual_room, next_room);
							   switch (door_direction_next_room){
									case north: next_room->north.open_door(); break;
									case south:next_room->south.open_door(); break;
									case east:next_room->east.open_door(); break;
									case west:next_room->west.open_door(); break;
							   }
				}
							break;
				case east:{
							  Room* next_room = actual_room->east.get_next_room();
							  actual_room->east.open_door();
							  actions door_direction_next_room = find_connection_direction(actual_room, next_room);
							  switch (door_direction_next_room){
									case north: next_room->north.open_door(); break;
									case south:next_room->south.open_door(); break;
									case east:next_room->east.open_door(); break;
									case west:next_room->west.open_door(); break;
							  }
				}
							break;
				case west:{
							  Room* next_room = actual_room->west.get_next_room();
							  actual_room->west.open_door();
							  actions door_direction_next_room = find_connection_direction(actual_room, next_room);
							  switch (door_direction_next_room){
									case north: next_room->north.open_door(); break;
									case south:next_room->south.open_door(); break;
									case east:next_room->east.open_door(); break;
									case west:next_room->west.open_door(); break;
							  }
				}
							break;
			}
			return "The door is open now.";
		}
		else return "There isn't any door in this direction.";
	}
	else return "I don't recognise this direction.";
}

bool is_a_direction(actions interpreted){
	if (interpreted == north || interpreted == south || interpreted == east || interpreted == west) return true;
	else return false;
}

actions find_connection_direction(Room* actual_room, Room* next_room){
	if (next_room->north.get_next_room() == actual_room) return north;
	else if (next_room->east.get_next_room() == actual_room) return east;
	else if (next_room->west.get_next_room() == actual_room) return west;
	else if (next_room->south.get_next_room() == actual_room) return south;
}