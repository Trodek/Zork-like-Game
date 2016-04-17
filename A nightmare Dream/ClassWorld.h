#ifndef _World_
#define _World_

class Entity;
class Player;

class World :public Entity{
private:
	Player* player;
	bool first_loop=true;
public:
	//Constructor
	World();

	~World();

	bool Play();

	bool CheckInput(dynArray<MyString>& words);

};


#endif