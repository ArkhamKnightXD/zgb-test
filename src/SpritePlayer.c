#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

//Las animaciones deben de ser definidas con array de Unsingned integer
const UINT8 idle_animation[] = {1, 0}; //The first number indicates the number of frames

//Debido a que el primer numero indica el numero de frames, mi animacion de walk 
//tiene 2 frames, en los siguientes index indico la posicion de mis frames de animaciones que son el 1 y 2
const UINT8 walking_animation[] = {2, 1, 2};

//El collider de nuestro player se encuentra en el archivo player.gbr.meta, ahi podemos cambiar la posicion en X y Y del collider y tambien su width y height

void START() {
}

void PlayerMovement(){

	if(KEY_PRESSED(J_UP)) {

		//Cuando ya agregamos collision debemos reemplazar esta linea por translateSprite
		//THIS->y--;
		//El primer parametro es This el segundo el valor en que aumentara X y el 3ero el valor que aumentara y
		TranslateSprite(THIS, 0, -1 << delta_time);

//Esta funcion se encarga de manejar las animaciones, le debo de enviar This (se refiere a 
//la instancia de spritePlayer), luego indico las animaciones y al final a la cantidad de fps que se ejecutaran 
//15 es lo ideal para juego de gb 30 es demasiado
		SetSpriteAnim(THIS, walking_animation, 15);
	} 
	if(KEY_PRESSED(J_DOWN)) {

		//If you add too many enemies on your map you might notice a big slowdown that at some points can even make the game unplayable.
		//This can be improved a little bit using the var delta_time that:
		//Will be 0 when the frame rate is ~60fps Will be 1 otherwise

		//You can use this var to multiply the current amount of movement of your sprites (x << 0 is the same as multiplying by 1
		// and x << 1 is the same as multiplying by 2). This is how your update method should look like on your SpritePlayer.c
		TranslateSprite(THIS, 0, 1 << delta_time);

		SetSpriteAnim(THIS, walking_animation, 15);
	}
	if(KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -1 << delta_time, 0);

		SetSpriteAnim(THIS, walking_animation, 15);

	}
	if(KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, 1 << delta_time, 0);

		SetSpriteAnim(THIS, walking_animation, 15);
	}

//Cuando no se a presionado ningun boton, ejecuto el idle animation
	if(keys == 0) {
		SetSpriteAnim(THIS, idle_animation, 15);
	}

}

//Manejando la collision con mi enemigo, me parece que aqui busco todos los sprite y voy comparando 
//a ver si el sprite del player collisiono con el sprite del enemigo
void CheckCollisionWithEnemy(){
	
	UINT8 index;
	Sprite* actualSprite;

//SPRITEMANAGER_ITERATE is a macro that iterates through all the active sprites, if the sprite is of type SPRITE_ENEMY then we use the function 
//CheckCollision to check if we are colliding with it (do it in this order). If that happens then SetState is called unloading 
//the current state and loading the state passed as paramenter (even if it is the current one, like in this case)

	SPRITEMANAGER_ITERATE(index, actualSprite) {
		if(actualSprite->type == SpriteEnemy) {
			//En resumen cuando el sprite del player colisiona con el del enemy, resetea el juego
			if(CheckCollision(THIS, actualSprite)) {
				SetState(StateGame);
			}
		}
	}
}

void UPDATE() {

	PlayerMovement();

	//Se recomienda llamar este codigo al final del update
	CheckCollisionWithEnemy();
}


void DESTROY() {
}