#include "sdl_error_util.h"
#include <string>

void SDLError::SDLPrintError(void* sdl_error, std::string source_file_path){
  if (sdl_error == nullptr) {
    std::cout << "SDL Error! " << "Path: " << source_file_path << " Error: " << SDL_GetError() << std::endl;
    exit(1);
  }
}
