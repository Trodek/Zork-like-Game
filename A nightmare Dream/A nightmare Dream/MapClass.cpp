#include "MapClass_Header.h"

Map::Map(){
	bedroom = NULL;
	parents_room = NULL;
	kitchen = NULL;
	house_street = NULL;
	sagrada_familia = NULL;
	placa_glories = NULL;
	parc_ciutadella = NULL;
	parc_guell = NULL;
	harbor = NULL;
	liceu = NULL;
	placa_catalunya = NULL;
	monjuic_palace = NULL;
	sants = NULL;
	camp_nou = NULL;
}

void Map::set_bedroom(Room* my_room){
	bedroom = my_room;
}

void Map::set_parents_room(Room* parents){
	parents_room = parents;
}

void Map::set_kitchen(Room* cook){
	kitchen = cook;
}

void Map::set_house_street(Room* street){
	house_street = street;
}

void Map::set_sagrada_familia(Room* sagrada){
	sagrada_familia = sagrada;
}

void Map::set_parc_guell(Room* guell){
	parc_guell = guell;
}

void Map::set_placa_glories(Room* glories){
	placa_glories = glories;
}

void Map::set_parc_ciutadella(Room* ciutadella){
	parc_ciutadella = ciutadella;
}

void Map::set_harbor(Room* deck){
	harbor = deck;
}

void Map::set_liceu(Room* theater){
	liceu = theater;
}

void Map::set_placa_catalunya(Room* catalunya){
	placa_catalunya = catalunya;
}

void Map::set_monjuic_palace(Room* monjuic){
	monjuic_palace = monjuic;
}

void Map::set_sants(Room* train){
	sants = train;
}

void Map::set_camp_nou(Room* barca){
	camp_nou = barca;
}