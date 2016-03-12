#include <iostream>
#include <string>
#include <algorithm>
#include "RoomClass_Header.h"
#include "GameFunctions_Header.h"
#include "MapClass_Header.h"
#include "PlayerClass_Header.h"
#include "RoomClass_Header.h"
#include "WorldClass_Header.h"
#include "GameLogicFunctions_Header.h"

using namespace std;

void CreateWorld(World* barcelona){

	// Creation of the Map
	barcelona->room_map = new Map;

	//Setting the correct information for each Room:
	barcelona->room_map->set_bedroom(new Room("Bedroom", "Nothing seems to work. I just see the computer screen lighting with a message."));
	barcelona->room_map->set_kitchen(new Room("Kitchen", "Here is where I used to prepare my meals. You can see some objects arround you."));
	barcelona->room_map->set_parents_room(new Room("Parents Room", "My parents room... Better don't think about what they do here... Maybe I found something in the wardrobe."));
	barcelona->room_map->set_house_street(new Room("House Street", "Why there is noone in the streets, usually there's a lot of people walking."));
	barcelona->room_map->set_sagrada_familia(new Room("Sagrada Familia", "I hate these cranes... Wait a minute... IT'S FINISHED!! WTF IS HAPPENING HERE!!"));
	barcelona->room_map->set_parc_guell(new Room("Parc Guell", "It's quiet than it used to be. But... I miss something... OMG WHERE IS THE DRAGON STATUE!!"));
	barcelona->room_map->set_placa_glories(new Room("Placa Glories", "WOW! Seems that everyone just desapeared from here! Cars are still in the middle of the streets."));
	barcelona->room_map->set_parc_ciutadella(new Room("Parc de la Ciutadella", "I always like this parc. In the fountain used to be lots of coins that people throw."));
	barcelona->room_map->set_harbor(new Room("Harbor", "This harbor smell bad even without noone in the city. Seems that ships are all moored. Did they finish the extension works?"));
	barcelona->room_map->set_liceu(new Room("Liceu", "I'd like to come to this theater some day, but I don't know if I like this type of music enough."));
	barcelona->room_map->set_placa_catalunya(new Room("Placa Catalunya", "This is the place where all the tourists lose their pocket. I should find somthing in the shops arround."));
	barcelona->room_map->set_monjuic_palace(new Room("Monjuic Palace", "I come to the museum a week ago, I'm not sure if i can find something usefull in a museum..."));
	barcelona->room_map->set_sants(new Room("Sants", "This train station is huge... I can easily get lost in the corridors without some light."));
	barcelona->room_map->set_camp_nou(new Room("Camp Nou", "IT'S OPEN!! I can't believe I'm trading the grass. Seems they forgot the balls of the last training."));

	//Setting the connections between rooms:
		//bedroom
	barcelona->room_map->bedroom->north.set_connection(true, false, true, barcelona->room_map->kitchen, 1);
		//kitchen
	barcelona->room_map->kitchen->east.set_connection(true, false, true, barcelona->room_map->bedroom, 1);
	barcelona->room_map->kitchen->south.set_connection(true, false, true, barcelona->room_map->parents_room, 1);
	barcelona->room_map->kitchen->west.set_connection(true, true, true, barcelona->room_map->house_street, 1);
		//parents room
	barcelona->room_map->parents_room->north.set_connection(true, false, true, barcelona->room_map->kitchen, 1);
		//house street
	barcelona->room_map->house_street->east.set_connection(true, true, true, barcelona->room_map->kitchen, 1);
	barcelona->room_map->house_street->south.set_connection(true, false, false, barcelona->room_map->sagrada_familia, 2);
		//sagrada familia
	barcelona->room_map->sagrada_familia->north.set_connection(true, false, false, barcelona->room_map->parc_guell, 3);
	barcelona->room_map->sagrada_familia->east.set_connection(true, false, false, barcelona->room_map->house_street, 2);
	barcelona->room_map->sagrada_familia->west.set_connection(true, false, false, barcelona->room_map->camp_nou, 6);
	barcelona->room_map->sagrada_familia->south.set_connection(true, false, false, barcelona->room_map->placa_glories, 2);
		//plaça glories
	barcelona->room_map->placa_glories->north.set_connection(true, false, false, barcelona->room_map->sagrada_familia, 2);
	barcelona->room_map->placa_glories->west.set_connection(true, false, false, barcelona->room_map->placa_catalunya, 2);
	barcelona->room_map->placa_glories->south.set_connection(true, false, false, barcelona->room_map->parc_ciutadella, 3);
		//parc de la ciutadella
	barcelona->room_map->parc_ciutadella->north.set_connection(true, false, false, barcelona->room_map->placa_glories, 3);
	barcelona->room_map->parc_ciutadella->west.set_connection(true, false, false, barcelona->room_map->harbor, 3);
		//harbor
	barcelona->room_map->harbor->east.set_connection(true, false, false, barcelona->room_map->parc_ciutadella, 3);
	barcelona->room_map->harbor->north.set_connection(true, true, true, barcelona->room_map->liceu, 1);
		//Liceu
	barcelona->room_map->liceu->north.set_connection(true, true, true, barcelona->room_map->placa_catalunya, 2);
	barcelona->room_map->liceu->south.set_connection(true, true, true, barcelona->room_map->harbor, 2);
		//plaça catalunya
	barcelona->room_map->placa_catalunya->north.set_connection(true, false, false, barcelona->room_map->sants, 4);
	barcelona->room_map->placa_catalunya->east.set_connection(true, false, false, barcelona->room_map->placa_glories, 2);
	barcelona->room_map->placa_catalunya->west.set_connection(true, true, true, barcelona->room_map->monjuic_palace, 4);
	barcelona->room_map->placa_catalunya->south.set_connection(true, true, true, barcelona->room_map->liceu, 2);
		//Montjuic
	barcelona->room_map->monjuic_palace->east.set_connection(true, true, true, barcelona->room_map->placa_catalunya, 4);
	barcelona->room_map->monjuic_palace->north.set_connection(true, true, true, barcelona->room_map->sants, 2);
		//Sants
	barcelona->room_map->sants->east.set_connection(true, false, false, barcelona->room_map->placa_catalunya, 3);
	barcelona->room_map->sants->west.set_connection(true, true, false, barcelona->room_map->camp_nou, 2);
	barcelona->room_map->sants->south.set_connection(true, true, true, barcelona->room_map->monjuic_palace, 2);
		//Camp Nou
	barcelona->room_map->camp_nou->east.set_connection(true, false, false, barcelona->room_map->sagrada_familia, 6);
	barcelona->room_map->camp_nou->south.set_connection(true, true, false, barcelona->room_map->sants, 2);
		//Parc Guell
	barcelona->room_map->parc_guell->south.set_connection(true, false, false, barcelona->room_map->sagrada_familia, 3);

	//Creating the player and positioning the player in the bedroom
	barcelona->character = new Player(barcelona->room_map->bedroom);

}

void CleanWorld(World* barcelona){

	//deallocating the Player
	delete barcelona->character;

	//deallocating the Rooms
	delete barcelona->room_map->bedroom;
	delete barcelona->room_map->camp_nou;
	delete barcelona->room_map->kitchen;
	delete barcelona->room_map->parents_room;
	delete barcelona->room_map->house_street;
	delete barcelona->room_map->sagrada_familia;
	delete barcelona->room_map->placa_glories;
	delete barcelona->room_map->parc_ciutadella;
	delete barcelona->room_map->parc_guell;
	delete barcelona->room_map->harbor;
	delete barcelona->room_map->placa_catalunya;
	delete barcelona->room_map->liceu;
	delete barcelona->room_map->monjuic_palace;
	delete barcelona->room_map->sants;

	//deallocatin the Map
	delete barcelona->room_map;

	//deallocating the World
	delete barcelona;
}

void GameLoop(World* barcelona){

	cout << endl << "			Welcome to A Nightmare Dream." << endl << "			   A text base adventure." << endl;
	print_help();

	bool end = false;
	bool room_changed = true;
	string input;
	actions input_interpreted;
	while (!end){
		if (room_changed){
			cout << endl << "I'm in the " << barcelona->character->actual->get_name()<<'.' << endl << endl;
			cout << barcelona->character->actual->get_description() << endl;
		}
		room_changed = true;
		cout << endl<< ">> What should I do?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input_interpreted = interpret_input(input);
		switch (input_interpreted){
			case north: {
							if (can_move(input_interpreted, barcelona->character->actual)){
								if (no_closed(input_interpreted, barcelona->character->actual)){
									barcelona->character->change_room(barcelona->character->actual->north.get_next_room());
								}
								else {
									cout << endl << "The door is locked!" << endl;
									room_changed = false;
								}
							}
							else {
								cout << endl << "I can't move in this direction." << endl;
								room_changed = false;
							}
						} 
						break;
			case south: {
							if (can_move(input_interpreted, barcelona->character->actual)){
								if (no_closed(input_interpreted, barcelona->character->actual)){
									barcelona->character->change_room(barcelona->character->actual->south.get_next_room());
								}
								else {
									cout << endl << "The door is locked!" << endl;
									room_changed = false;
								}
							}
							else {
								cout << endl << "I can't move in this direction." << endl;
								room_changed = false;
							}
						}
						break;
			case east: {
						   if (can_move(input_interpreted, barcelona->character->actual)){
							   if (no_closed(input_interpreted, barcelona->character->actual)){
								   barcelona->character->change_room(barcelona->character->actual->east.get_next_room());
							   }
							   else {
								   cout << endl << "The door is locked!" << endl;
								   room_changed = false;
							   }
						   }
						   else {
							   cout << endl << "I can't move in this direction." << endl;
							   room_changed = false;
						   }
						}
						break;
			case west: {
						   if (can_move(input_interpreted, barcelona->character->actual)){
							   if (no_closed(input_interpreted, barcelona->character->actual)){
								   barcelona->character->change_room(barcelona->character->actual->west.get_next_room());
							   }
							   else {
								   cout << endl << "The door is locked!" << endl;
								   room_changed = false;
							   }
						   }
						   else {
							   cout << endl << "I can't move in this direction." << endl;
							   room_changed = false;
						   }
						}
						break;
			case open_door: cout << open_connection(barcelona->character->actual) << endl; room_changed = false; break;
			case close_door: cout << close_connection(barcelona->character->actual) << endl; room_changed = false; break;
			case not_recognised: cout << endl << "I don't recognise that order." << endl; room_changed = false; break;
			case look_arround: look_room(barcelona->character->actual); room_changed = false; break;
			case help: print_help(); room_changed = false; break;
			case quit: end = true; break;
		}

	}

}