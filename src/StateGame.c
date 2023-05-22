#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

IMPORT_MAP(map);

//Collisionable tiles are declared as an array of UINT8 ended with 0. 
//If you open the file tiles.gbr you will see that we only have two tiles (the first one is empty and we don't want that to be collidable).
// Declare the next array on StateGame.c
UINT8 collision_tiles[] = {1, 0};


//Todo sprite que debe de renderizarse lo defino aqui
void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 10, 50);

	SpriteManagerAdd(SpriteEnemy2, 10, 10);

//Aqui agrego el sprite de mi enemigo y lo inicializo en la posicion (70, 50). Puedo tambien agregar 
//a los enemigos por codigo o por mi tilemap. Por lo tanto comentare esto.
	//SpriteManagerAdd(SpriteEnemy, 100, 50);

	//Metodo encargado de hacer scroll, si queremos que haya collision debemos de pasarle el array collision tiles como 2do parametro y reemplazar el 0
	InitScroll(BANK(map), &map, collision_tiles, 0);
}

void UPDATE() {
}
