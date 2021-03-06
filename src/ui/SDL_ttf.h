#ifndef UI_SDL_TTF_H
#define UI_SDL_TTF_H

#include <SDL2/SDL_ttf.h>

#include <util/RAIIhelper.h>


/**
 * SDL ttf header wrapper
 * @author SwarmingLogic (Roald Fernandez)
 */
CREATE_RAII_UP(TTF_Font,     TTF_CloseFont)       FontPtr;

#endif
