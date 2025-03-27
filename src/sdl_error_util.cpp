#include "sdl_error_util.h"

void SDLError::SDLPrintError(void* sdl_error){
  if (sdl_error == nullptr) {
    std::cout << "Failed to create SDL window! Error: " << SDL_GetError() << std::endl;
    exit(1);
  }
}
