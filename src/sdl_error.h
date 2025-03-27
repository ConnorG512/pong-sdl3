#include <cstdlib>
#include <iostream>
#include <SDL3/SDL_error.h>

namespace SDLError {
  // Will exit the program if there is an error with the error code of 1.
  void SDLPrintError(void* sdl_error);
}
