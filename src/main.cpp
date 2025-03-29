#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_timer.h>
#include <cstdio>
#include <memory>

#include "game_window.h"
#include "sdl_error_util.h"
#include "sprite.h"


int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong", 1600, 900)};
  
  SDL_FRect rectangle {100, 350, 10, 200};
  bool result = SDL_RenderRect(game_window->m_game_renderer, &rectangle);
  printf("Recrangle result %b ", result);
  printf("Renderer address from Rec: %p \n", game_window->m_game_renderer);
  SDLError::SDLPrintError(game_window->m_game_renderer, "src/main.cpp");
  
  // Sprite creation
  std::unique_ptr<Sprite> sprite_1{ new Sprite(100, 300, 10, 300, 255, 255, 255, 255, game_window->m_game_renderer)};
  std::unique_ptr<Sprite> sprite_2{ new Sprite(1500, 300, 10, 300, 255, 255, 255, 255, game_window->m_game_renderer)};

  while (!finished_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        finished_running = true;  
      }
    } 
    // Game logic here: 
    SDL_Delay(16);
    // Background colour
    SDL_SetRenderDrawColor(game_window->m_game_renderer, 0, 0, 0, 255);
    SDL_RenderClear(game_window->m_game_renderer);
    
    // Player sprites
    sprite_1->colorSprite();
    sprite_2->colorSprite(); 

    SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
