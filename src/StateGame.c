#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

IMPORT_MAP(map);

//Collisionable tiles are declared as an array of UINT8 ended with 0. 
//If you open the file tiles.gbr you will see that we only have two tiles (the first one is empty and we don't want that to be collidable).
// Declare the next array on StateGame.c
UINT8 collision_tiles[] = {1, 0};


void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);

	//Metodo encargado de hacer scroll, si queremos que haya collision debemos de pasarle el array collision tiles como 2do parametro y reemplazar el 0
	InitScroll(BANK(map), &map, collision_tiles, 0);
}

void UPDATE() {
}
