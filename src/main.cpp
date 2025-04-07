#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <cstdio>
#include <memory>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_keyboard.h>

#include "game_window.h"
#include "player_paddle.h"
#include "sdl_error_util.h"

int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong")};
  // Get SDL Keyboard state
  const bool* keyboard_state = SDL_GetKeyboardState(nullptr);
  // Player Paddle
  auto player_paddle_1 = std::make_unique<PlayerPaddle>(
        100.0f, 300.0f, 250.0f, 250.0f, 6.0f,
        game_window->m_game_renderer,
        keyboard_state,
        26, // PADDLE UP KEY "W" 
        22  // PADDLE DOWN KEY "S"
        );

  while (!finished_running) {  
    SDL_Event event;

    SDL_Delay(16);
    // Background colour
    SDL_SetRenderDrawColor(game_window->m_game_renderer, 0, 0, 0, 255);
    while (SDL_PollEvent(&event)) {  
    } 

    // Clear the backbuffer
    SDL_RenderClear(game_window->m_game_renderer);

    player_paddle_1->drawSpriteToScreen();
    
    // Exit the game with escape.
    if (keyboard_state [SDL_SCANCODE_ESCAPE]) {
      finished_running = true; 
    }
    // GAME LOGIC

    // Game logic here: 
      // Present backbuffer
      SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
