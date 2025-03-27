#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <cstdio>
#include <unistd.h>

#include "sdl_window.h"

int main (int, char **) {
  bool finished_running { false };

  GameWindow game_window = {"Pong", 1600, 900};
  
  while (!finished_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        finished_running = true;  
      }
    } 
    // Game logic here: 

  }

  return 0;
}
