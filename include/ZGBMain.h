#ifndef ZGBMAIN_H
#define ZGBMAIN_H

//Here I defined all my states. The states works like screens in libgdx
//I have to create a file with the same name. And in that file I have to code the behaviour of the state ()

#define STATES \
_STATE(StateGame)\
STATE_DEF_END

//Aqui indico mi sprites y el objeto relacionado a este, Mi archivo SpriteEnemy esta asocioado con el sprite enemy
#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteEnemy, enemy)\
_SPRITE_DMG(SpriteEnemy2, enemy2)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif