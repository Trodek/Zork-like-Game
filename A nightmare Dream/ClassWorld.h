#ifndef _World_
#define _World_

class Entity;
class Player;

class World :public Entity{
public:
	Player* player;
	World* me = this;
public:
	//Constructor
	World();

	~World();

	bool Play();

	bool CheckInput(dynArray<MyString>& words);

};


#endif