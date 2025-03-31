#include <SDL3/SDL_timer.h>
#include <cstdio>
#include <memory>

#include "game_window.h"
#include "player.h"
#include "sdl_error_util.h"
#include "divider.h"

int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong", 1600, 900)};
  SDLError::SDLPrintError(game_window->m_game_renderer, "src/main.cpp");
  printf("game_window address: %p \n", &game_window);  
  // Divider 
  std::unique_ptr<Divider> background_divider{ new Divider(game_window->m_game_renderer)};
  // Player creation
  std::unique_ptr<Player> player_paddle_1 { new Player(100, 300, 10, 300, game_window->m_game_renderer)};
  printf("player_paddle_1 address: %p \n", &player_paddle_1);  
  std::unique_ptr<Player> player_paddle_2 { new Player(1500, 300, 10 ,300, game_window->m_game_renderer)};
  printf("player_paddle_2 address: %p \n", &player_paddle_2);  
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
    // Divider 
    background_divider->drawDividerOnScreen();
    // Player sprites
    player_paddle_1->colorSprite();
    player_paddle_2->colorSprite();
    SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
