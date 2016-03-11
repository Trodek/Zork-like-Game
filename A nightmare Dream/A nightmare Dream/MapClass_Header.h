#ifndef _MapClass_
#define _MapClass_

#include "RoomClass_Header.h"

class Map {

public:
	Room* bedroom;
	Room* parents_room;
	Room* kitchen;
	Room* house_street;
	Room* sagrada_familia;
	Room* parc_guell;
	Room* placa_glories;
	Room* parc_ciutadella;
	Room* harbor;
	Room* liceu;
	Room* placa_catalunya;
	Room* monjuic_palace;
	Room* sants;
	Room* camp_nou;

	Map();
	void set_bedroom(Room* my_room);
	void set_parents_room(Room* parents);
	void set_kitchen(Room* cook);
	void set_house_street(Room* street);
	void set_sagrada_familia(Room* sagrada);
	void set_parc_guell(Room* guell);
	void set_placa_glories(Room* glories);
	void set_parc_ciutadella(Room* ciutadella);
	void set_harbor(Room* deck);
	void set_liceu(Room* theater);
	void set_placa_catalunya(Room* catalunya);
	void set_monjuic_palace(Room* monjuic);
	void set_sants(Room* train);
	void set_camp_nou(Room* barca);

};

#endif