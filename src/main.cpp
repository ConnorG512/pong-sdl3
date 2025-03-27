#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_mutex.h>
#include <SDL3/SDL_video.h>
#include <cstdio>
#include <iostream>
#include <ostream>

int main (int , char **) {
  SDL_Window *game_window;
  bool done{false}; 

  game_window = SDL_CreateWindow(
      "Pong",
      1600,
      900,
      SDL_WINDOW_OPENGL
      );
  
  if (game_window == nullptr) {
    std::cout << "SDL Error, could not get window!" << SDL_GetError() << std::endl;
    return 1;
  }

  // Loop
  while (!done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }
  }

  SDL_DestroyWindow(game_window);
  SDL_Quit();
  return 0;
}
