#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

//Las animaciones deben de ser definidas con array de Unsingned integer
const UINT8 anim_idle[] = {1, 0}; //The first number indicates the number of frames

//Debido a que el primer numero indica el numero de frames, mi animacion de walk 
//tiene 2 frames, en los siguientes index indico la posicion de mis frames de animaciones que son el 1 y 2
const UINT8 anim_walk[] = {2, 1, 2};

//El collider de nuestro player se encuentra en el archivo player.gbr.meta, ahi podemos cambiar la posicion en X y Y del collider y tambien su width y height

void START() {
}

void UPDATE() {

	UINT8 i;
	Sprite* spr;

//Manejando la collision con mi enemigo
	SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SpriteEnemy) {
			if(CheckCollision(THIS, spr)) {
				SetState(StateGame);
			}
		}
	}

	if(KEY_PRESSED(J_UP)) {

		//Cuando ya agregamos collision debemos reemplazar esta linea por translateSprite
		//THIS->y--;
		//El primer parametro es This el segundo el valor en que aumentara X y el 3ero el valor que aumentara y
		TranslateSprite(THIS, 0, -1);

//Esta funcion se encarga de manejar las animaciones, le debo de enviar This (se refiere a 
//la instancia de spritePlayer), luego indico las animaciones y al final a la cantidad de fps que se ejecutaran 
//15 es lo ideal para juego de gb 30 es demasiado
		SetSpriteAnim(THIS, anim_walk, 15);
	} 
	if(KEY_PRESSED(J_DOWN)) {
		TranslateSprite(THIS, 0, 1);

		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -1, 0);

		SetSpriteAnim(THIS, anim_walk, 15);

	}
	if(KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, 1, 0);

		SetSpriteAnim(THIS, anim_walk, 15);
	}

//Cuando no se a presionado ningun boton, ejecuto el idle animation
	if(keys == 0) {
		SetSpriteAnim(THIS, anim_idle, 15);
	}
}


void DESTROY() {
}