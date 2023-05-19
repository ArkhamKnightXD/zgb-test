#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"

typedef struct {
	UINT8 vy;
} CUSTOM_DATA;

void START() {

    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
	data->vy = 1;
}

void UPDATE() {

//Manejando las colision con el player
    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
	if(TranslateSprite(THIS, 0, data->vy)) {
		data->vy = -data->vy;
	}
}

void DESTROY() {
}