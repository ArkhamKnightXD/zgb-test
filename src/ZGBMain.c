#include "ZGBMain.h"
#include "Math.h"

UINT8 next_state = StateGame;

//Luckily ZGB will let you place enemies on the map using the Game Boy Map Builder. 
//This thing is accomplished by the function GetTileReplacement in ZGBMain.c

//This function is called for any tile that its placed in the background.

UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == StateGame) {

		//This default function will spawn and enemy of type 0 when the tile is 255, and enemy of type 1 when the tile is 254, 
		//and enemy of type 2 when the tile is 253... and so on
		if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
			*tile = 0;
			return 255 - (UINT16)*tile_ptr;
		}

		*tile = *tile_ptr;
	}

	return 255u;
}