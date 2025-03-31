#include <SDL3/SDL_events.h>
#include <SDL3/SDL_timer.h>
#include <cstdio>
#include <memory>
#include <SDL3/SDL_keycode.h>

#include "game_window.h"
#include "player.h"
#include "sdl_error_util.h"
#include "divider.h"

int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong")};
  // Divider 
  std::unique_ptr<Divider> background_divider{ new Divider(game_window->m_game_renderer)};
  // Player creation
  std::unique_ptr<Player> player_paddle_1 { new Player(100, 300, 10, 300, game_window->m_game_renderer)};
  std::unique_ptr<Player> player_paddle_2 { new Player(1500, 300, 10 ,300, game_window->m_game_renderer)};

  printf("game_window address: %p \n", &game_window);  
  printf("player_paddle_1 address: %p \n", &player_paddle_1);  
  printf("player_paddle_2 address: %p \n", &player_paddle_2);  
  while (!finished_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      // Exit by hitting the close button on window.
      switch (event.type) {
        case SDL_EVENT_QUIT:
          finished_running = true;
        break;
        
        // Exit the game with a button press.
        case SDL_EVENT_KEY_DOWN:
          switch (event.key.key) {
            // Escape key
            case SDLK_ESCAPE:
              finished_running = true;
              printf("Escape key has been pressed! \n");
              break;
            case SDLK_W:
              printf("W pressed! \n");
              break;
            case SDLK_S:
              printf("S Pressed! \n");
              break;
            case SDLK_I:
              printf("I Pressed! \n");
              break;
            case SDLK_K:
              printf("K Pressed! \n");
              break;
          }
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
