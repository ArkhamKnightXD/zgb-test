#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateGame)\
STATE_DEF_END

//Aqui indico mi sprites y el objeto relacionado a este, Mi archivo SpriteEnemy esta asocioado con el sprite enemy
#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteEnemy, enemy)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif