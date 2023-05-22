#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

typedef struct {

	UINT8 velocityX;

} CUSTOM_DATA;


void START() {

    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;

	data->velocityX = 1;
}

void UPDATE() {

    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;

	if(TranslateSprite(THIS, data->velocityX << delta_time, 0)) {
		data->velocityX = -data->velocityX;
	}

	UINT8 spriteIndex;
	Sprite* collisionSprite;


	SPRITEMANAGER_ITERATE(spriteIndex, collisionSprite) {

		if(collisionSprite->type == SpritePlayer) {

//Si mi player colisiona con este enemigo la velocidad de este se volvera 0
			if(CheckCollision(THIS, collisionSprite)) 
				data->velocityX = 0;
			
		}
	}
}

void DESTROY() {
}