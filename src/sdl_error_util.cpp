#include "sdl_error_util.h"
#include <cassert>
#include <string>

void SDLError::SDLPrintError(void* sdl_error, std::string source_file_path){
  assert(sdl_error && "SDL Error, returned null!"); 
}
