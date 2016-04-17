#include <stdio.h>
#include "ClassEntity.h"
#include "ClassConnection.h"
#include "ClassItem.h"
#include "ClassPlayer.h"
#include "ClassWorld.h"
#include "ClassRoom.h"

World::World(){
	//Create Rooms
	Room* bedroom = new Room("Bedroom", "Nothing seems to work. I just see the computer screen lighting with a message.");
	Room* kitchen = new Room("Kitchen", "Here is where I used to prepare my meals. You can see some objects arround you.");
	Room* parents = new Room("Parents Room", "My parents room... Better don't think about what they do here... Maybe I found something in the wardrobe.");
	Room* hstreet = new Room("House Street", "Why there is noone in the streets, usually there's a lot of people walking.");
	Room* sagradafamilia = new Room("Sagrada Familia", "I hate these cranes... Wait a minute... IT'S FINISHED!! WTF IS HAPPENING HERE!!");
	Room* parcguell = new Room("Parc Guell", "It's quiet than it used to be. But... I miss something... OMG WHERE IS THE DRAGON STATUE!!");
	Room* glories = new Room("Placa Glories", "WOW! Seems that everyone just desapeared from here! Cars are still in the middle of the streets.");
	Room* parcciutadella = new Room("Parc de la Ciutadella", "I always like this parc. In the fountain used to be lots of coins that people throw but it's too dark to see anything.");
	Room* harbor = new Room("Harbor", "This harbor smell bad even without noone in the city. Seems that ships are all moored. Did they finish the extension works?");
	Room* liceu = new Room("Liceu", "I'd like to come to this theater some day, but I don't know if I like this type of music enough.");
	Room* catalunya = new Room("Placa Catalunya", "This is the place where all the tourists lose their pocket. I should find somthing in the shops arround.");
	Room* montjuic = new Room("Monjuic Palace", "I come to the museum a week ago, I'm not sure if i can find something usefull in a museum...");
	Room* sants = new Room("Sants", "This train station is huge... I can easily get lost in the corridors without some light.");
	Room* campnou = new Room("Camp Nou", "IT'S OPEN!! I can't believe I'm trading the grass. Seems they forgot the balls of the last training.");
	
	contain.PushBack(bedroom);
	contain.PushBack(kitchen);
	contain.PushBack(parents);
	contain.PushBack(hstreet);
	contain.PushBack(sagradafamilia);
	contain.PushBack(parcguell);
	contain.PushBack(glories);
	contain.PushBack(parcciutadella);
	contain.PushBack(harbor);
	contain.PushBack(liceu);
	contain.PushBack(catalunya);
	contain.PushBack(montjuic);
	contain.PushBack(sants);
	contain.PushBack(campnou);

	//Items

	Item* Backpack = new Item("inventory", "Seems Doraemon's magic pocket. Everything can be put inside.");
	Item* Message = new Item("message", "Hi Marc,\nThis is your dream, be alone in the world. But maybe you realize that this is \nnot better than your normal life.\nIf you want to return to your normal life you must complete the puzzle this \nworld have.\nTip: Dont forget to eat.\nGood Luck", false, false, bedroom); 
	Item* RWardrobe = new Item("mywardrobe", "My wardrobe, I usually have some usefull things inside.", true,false, bedroom);
	Item* lantern = new Item("lantern", "Shit, doesn't have batteries.", true, true, RWardrobe);
	Item* stove = new Item("stove", "I'm lucky that it works with fuel and not with electricity. I can use it to prepare some food.", true, false, kitchen);
	Item* knive = new Item("knive", "The kinfe from yesterday dinner. Maybe mum forget to wash it.", false, true, kitchen);
	Item* water = new Item("water", "A bottle of water.", false, true, kitchen, 4);
	Item* cereal = new Item("cereals", "This are the Chocokrispies my mum eat every day.", false, true, kitchen, 10);
	Item* PWardrobe = new Item("parentswardrobe", "My parents wardrobe. I'm not sure about looking inside.", true, false, parents);
	Item* housekey = new Item("key1", "This key looks like the house key.", false, true, PWardrobe);
	Item* condom = new Item("condom", "Uggh! FUCK, IT'S USED!!!", true, true, PWardrobe);
	Item* bag = new Item("bag", "I can't get it, it is hanging from a Sagrada Familia's tower.", true, false, sagradafamilia);
	Item* paw1 = new Item("frontleftpaw", "A drake paw.", false, true, bag); 
	Item* stairs = new Item("stairs", "They look strange without the drake", true, false, parcguell);
	Item* redcar = new Item("ferrari", "This car look awesome, I wish I can have one some day.", true, false, glories);
	Item* bluecar = new Item("ibiza", "This Seat isn't awesome, I don't like it.", true, false, glories);
	Item* yellowcar = new Item("golf", "This Volkswagen car is OK.", true, false, glories);
	Item* whitecar = new Item("q5", "This is my mum car, maybe she was going to work.", true, false, glories);
	Item* blackcar = new Item("murcielago", "Lamborghini cars are beautiful.", true, false, glories);
	Item* paw2 = new Item("frontrightpaw", "A drake paw.", false, true, yellowcar); 
	Item* liceukey = new Item("key2", "This key looks old.", false, true, bluecar);
	Item* chest = new Item("chest", "An rusty chest.", true, true, parcciutadella);
	Item* tail = new Item("tail", "The drake tail.", false, true, chest); 
	Item* cement = new Item("cement", "Used to build things.", false, true, harbor); 
	Item* ship = new Item("ship", "A fisherman ship.", true, false, harbor);
	Item* batteries = new Item("batteries", "This batteris are usefull for the lantern.", false, true, ship);
	Item* piano = new Item("piano", "This piano look so expensive.", true, true, liceu);
	Item* violin = new Item("violin", "This is an Stradivarius, is awesome to see one before die.", true, true, liceu);
	Item* popcorn = new Item("popcorn", "Someone forgot to eat his popcorn.", false, true, liceu, 6);
	Item* body = new Item("body", "The drake body.", false, true, piano); 
	Item* key = new Item("key3", "An old golden key.", false, true, violin);
	Item* shopbag = new Item("shopbag", "Someone left his shopings here", true, true, catalunya);
	Item* meat = new Item("meat", "A steak. I can cook it.", false, true, shopbag);
	Item* fish = new Item("fish", "A sardine. Cooked will be tasty.", false, true, shopbag);
	Item* potatoes = new Item("potatoes", "I prefer Lay's but Mercadona ones are OK too.", false, true, shopbag, 8);
	Item* salat = new Item("salat", "I don't like vegetables but are better than nothing.", false, true, shopbag, 13);
	Item* battery = new Item("batteries", "Some batteries, they will fit in a lantern.", false, true, shopbag);
	Item* eggs = new Item("eggs", "Chicken eggs", false, true, shopbag);
	Item* cmeat = new Item("steak", "This cooked steak smells well.", false, true, nullptr, 20);
	Item* cfish = new Item("fried-fish", "All type of food taste better fried.", false, true, nullptr, 15);
	Item* omelette = new Item("omelet", "An spanish omelette.", false, true, nullptr, 17);
	Item* hat = new Item("cap", "This cap is strange. Why have a duck head glued in the front?", false, true, catalunya);
	Item* crown = new Item("crown", "An old XVth century crown.", true, true, montjuic);
	Item* head = new Item("head", "A drake head.", false, true, crown); 
	Item* chocolate = new Item("chocolate", "A chocolate bar.", false, true, sants, 6);
	Item* paw3 = new Item("backleftpaw", "A drake paw.", false, true, sants); 
	Item* bench = new Item("bench", "THAT'S FCB BENCH, I NEVER THOUGHT I CAN BE HERE ONE DAY.", true, false, campnou);
	Item* ballnet = new Item("ballnet", "A net full of FCB balls.", true, false, campnou);
	Item* ball = new Item("ball", "A FCB ball.", false, true, ballnet);
	Item* paw4 = new Item("backrightpaw", "A drake paw.", false, true, bench); 
	Item* drake = new Item("drake", "The camplete drake.", true, true);

	contain.PushBack(Backpack);
	contain.PushBack(Message);
	contain.PushBack(RWardrobe);
	contain.PushBack(lantern);
	contain.PushBack(stove);
	contain.PushBack(knive);
	contain.PushBack(water);
	contain.PushBack(cereal);
	contain.PushBack(PWardrobe);
	contain.PushBack(housekey);
	contain.PushBack(condom);
	contain.PushBack(bag);
	contain.PushBack(paw1);
	contain.PushBack(stairs);
	contain.PushBack(redcar);
	contain.PushBack(bluecar);
	contain.PushBack(yellowcar);
	contain.PushBack(whitecar);
	contain.PushBack(blackcar);
	contain.PushBack(paw2);
	contain.PushBack(liceukey);
	contain.PushBack(chest);
	contain.PushBack(tail);
	contain.PushBack(cement);
	contain.PushBack(ship);
	contain.PushBack(batteries);
	contain.PushBack(piano);
	contain.PushBack(violin);
	contain.PushBack(popcorn);
	contain.PushBack(body);
	contain.PushBack(key);
	contain.PushBack(shopbag);
	contain.PushBack(meat);
	contain.PushBack(fish);
	contain.PushBack(potatoes);
	contain.PushBack(salat);
	contain.PushBack(battery);
	contain.PushBack(hat);
	contain.PushBack(cmeat);
	contain.PushBack(cfish);
	contain.PushBack(eggs);
	contain.PushBack(omelette);
	contain.PushBack(crown);
	contain.PushBack(head);
	contain.PushBack(chocolate);
	contain.PushBack(paw3);
	contain.PushBack(bench);
	contain.PushBack(ballnet);
	contain.PushBack(paw4);
	contain.PushBack(ball);
	contain.PushBack(drake);

	//Create Player
	player = new Player("Marc", "Blonde large hair", Backpack, bedroom, nullptr);
	Backpack->SetContainer(player);

	//Create Connections
		//bedroom
	contain.PushBack(new Connection(false, true, bedroom, kitchen, MyString("north"), 1, nullptr));
		//kitchen
	contain.PushBack(new Connection(false, true, kitchen, bedroom, MyString("east"), 1, nullptr));
	contain.PushBack(new Connection(false, true, kitchen, parents, MyString("south"), 1, nullptr));
	contain.PushBack(new Connection(true, true, kitchen, hstreet, MyString("west"), 1, housekey));
		//parents room
	contain.PushBack(new Connection(false, true, parents, kitchen, MyString("north"), 1, nullptr));
		//house street
	contain.PushBack(new Connection(true, true, hstreet, kitchen, MyString("east"), 1, housekey));
	contain.PushBack(new Connection(false, true, hstreet, sagradafamilia, MyString("south"), 2, nullptr));
		//sagrada familia
	contain.PushBack(new Connection(false, false, sagradafamilia, hstreet, MyString("east"), 2, nullptr));
	contain.PushBack(new Connection(false, false, sagradafamilia, parcguell, MyString("north"), 3, nullptr));
	contain.PushBack(new Connection(false, false, sagradafamilia, campnou, MyString("west"), 6, nullptr));
	contain.PushBack(new Connection(false, false, sagradafamilia, glories, MyString("south"), 2, nullptr));
		//Placa Glories
	contain.PushBack(new Connection(false, false, glories, sagradafamilia, MyString("north"), 2, nullptr));
	contain.PushBack(new Connection(false, false, glories, catalunya, MyString("west"), 2, nullptr));
	contain.PushBack(new Connection(false, false, glories, parcciutadella, MyString("south"), 3, nullptr));
		//Parc Ciutadella
	contain.PushBack(new Connection(false, false, parcciutadella, glories, MyString("north"), 3, nullptr));
	contain.PushBack(new Connection(false, false, parcciutadella, harbor, MyString("west"), 3, nullptr));
		//harbor
	contain.PushBack(new Connection(false, false, harbor, parcciutadella, MyString("east"), 3, nullptr));
	contain.PushBack(new Connection(true, true, harbor, liceu, MyString("north"), 1, liceukey)); 
		//liceu
	contain.PushBack(new Connection(true, true, liceu, harbor, MyString("south"), 1, liceukey)); 
	contain.PushBack(new Connection(true, true, liceu, catalunya, MyString("north"), 2, liceukey)); 
		//Placa Catalunya
	contain.PushBack(new Connection(true, true, catalunya, liceu, MyString("south"), 2, liceukey)); 
	contain.PushBack(new Connection(false, false, catalunya, sants, MyString("north"), 4, nullptr)); 
	contain.PushBack(new Connection(false, false, catalunya, glories, MyString("east"), 2, nullptr));
	contain.PushBack(new Connection(true, true, catalunya, montjuic, MyString("west"), 4, key)); 
		//monjuic
	contain.PushBack(new Connection(true, true, montjuic, catalunya, MyString("east"), 4, key)); 
	contain.PushBack(new Connection(true, true, montjuic, sants, MyString("north"), 2, key)); 
		//sants
	contain.PushBack(new Connection(true, true, sants, montjuic, MyString("south"), 2, key)); 
	contain.PushBack(new Connection(true, true, sants, campnou, MyString("west"), 2, nullptr)); 
	contain.PushBack(new Connection(false, false, sants, catalunya, MyString("east"), 4, nullptr)); 
		//camp nou
	contain.PushBack(new Connection(true, true, campnou, sants, MyString("south"), 2, nullptr)); 
	contain.PushBack(new Connection(false, false, campnou, sagradafamilia, MyString("east"), 6, nullptr)); 
		//parc guell
	contain.PushBack(new Connection(false, false, parcguell, sagradafamilia, MyString("south"), 3, nullptr));



}

World::~World(){
	delete player;
	for (int i = 0; i < contain.size(); i++){
		delete contain[i];
	}
}

bool World::Play(){

	if (first_loop){
		printf("\n%s\n", player->GetActualRoom()->GetName());
		printf("%s\n", player->GetActualRoom()->GetDescription());
		first_loop = false;
	}

	// Check if loose
	if (player->GetCurrentFood() <= 0){
		printf("I'm too hungry to continue...\n");
		printf("\n\n			You Lose.\n");
		return true;
	}

	//Check if win
	Item* stairs = nullptr;
	for (int i = 0; i < Game->contain.size(); i++){
		if (Game->contain[i]->GetType() == ITEM && Game->contain[i]->GetNameString() == "stairs"){
			stairs = dynamic_cast<Item*> (Game->contain[i]);
			break;
		}
	}
	if (stairs->HaveItem(MyString("drake"))!=nullptr){
		printf("\n\n'RIING''RIIING'\nWhat's that? Oh, my alarm cloack. Wait, what time is it?...6:30...\n");
		printf("WOW... This nightmare was too real...\n\n\n");
		printf("	CONGRATULATIONS! You save Marc from his nightmare dream.\n");
		return true;
	}

	//ask for input
	printf("\n>>What should I do?\n");

	char temp[50];
	fgets(temp, 50, stdin);
	MyString input(temp);
	input.tolowercase();
	dynArray<MyString> words;
	input.Tokenize(' ', words);
	printf("\n");
	if (words[0] == "quit"|| words[0]=="q")return true;
	return CheckInput(words);
	
}

bool World::CheckInput(dynArray<MyString>& words){
	bool ret = false;
	MyString temp;

	switch (words.size()){
	case 1:	{
				if (words[0] == "n" || words[0] == "north"){
					temp = "north";
					words.PushBack(temp);
					player->Go(words);
				}
				else if (words[0] == "w" || words[0] == "west"){
					temp = "west";
					words.PushBack(temp);
					player->Go(words);
				}
				else if(words[0] == "e" || words[0] == "east"){
					temp = "east";
					words.PushBack(temp);
					player->Go(words);
				}
				else if (words[0] == "s" || words[0] == "south"){
					temp = "south";
					words.PushBack(temp);
					player->Go(words);
				}
				else if (words[0] == "look"){
					player->Look(words);
				}
				else if (words[0] == "i" || words[0] == "inv" || words[0] == "inventory"){
					temp = "inventory";
					words.PushBack(temp);
					player->Look(words);
				}
				else if (words[0] == "unequip"){
					player->Unquip();
				}
				else printf("I don't understand that.");
				
		}
		break;
	case 2:{
			   if (words[0] == "go"){
				   if (words[1] == "n") words[1] = "north";
				   else if (words[1] == "s") words[1] = "south";
				   else if (words[1] == "e")words[1] = "east";
				   else if (words[1] == "w")words[1] = "west";
				   player->Go(words);
			   }
			   else if (words[0] == "pick"||words[0]=="get"){
				   player->Pick(words);
			   }
			   else if (words[0] == "close" || words[0] == "open"){
				   if (words[1] == "n") words[1] = "north";
				   else if (words[1] == "s") words[1] = "south";
				   else if (words[1] == "e")words[1] = "east";
				   else if (words[1] == "w")words[1] = "west";
				   player->ChangeDoor(words);
			   }
			   else if (words[0] == "look"){
				   player->Look(words);
			   }
			   else if (words[0] == "drop" || words[0] == "throw"){
				   player->Drop(words);
			   }
			   else if (words[0] == "equip"){
				   player->Equip(words);
			   }
			   else if (words[0] == "unequip"){
				   player->Unquip();
			   }
			   else if (words[0] == "eat"){
				   player->Eat(words);
			   }
			   else if (words[0] == "cook"){
				   player->Cook(words);
			   }
			   else if (words[0] == "create"){
				   player->Create(words);
			   }
			   else printf("I don't understand that.");
	}
		break;
	case 4:{
			   if (words[0] == "pick"|| words[0]=="get"){
				   player->Pick(words);
			   }
			   else if (words[0] == "drop" || words[0] == "put"){
				   player->Drop(words);
			   }
			   else printf("I don't understand that.");
	}
		break;
	}
	return ret;
}