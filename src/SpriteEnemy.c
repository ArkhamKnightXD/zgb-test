#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

// using typedef to define an alias for structure, the alias for this struct is CUSTOM_DATA
typedef struct {
	UINT8 vy;
} CUSTOM_DATA;

void START() {

    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
	//Aqui indico el movimiento en y que tendran mis enemigos, tengo que ver como logro manejar el movimiento en x tambien
	data->vy = 1;
}

void UPDATE() {

    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
//TranslateSprite will return the index of the tile when a collision happens or 0 otherwise. 
//In this case if there is a collision with the background the velocity of the sprite is negated making it changing its direction
	if(TranslateSprite(THIS, 0, data->vy << delta_time)) {
		data->vy = -data->vy;
	}
}

void DESTROY() {
}