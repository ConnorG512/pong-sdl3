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

#include "ball.h"
#include "game_window.h"
#include "player_paddle.h"
#include "sdl_error_util.h"

int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong")};
  // Get SDL Keyboard state
  const bool* keyboard_state = SDL_GetKeyboardState(nullptr);
  // Player Paddles
  auto player_paddle_1 = std::make_unique<PlayerPaddle>(
        1500.0f, 300.0f, 10.0f, 250.0f, 6.0f,
        game_window->m_game_renderer,
        keyboard_state,
        12, // PADDLE UP KEY "I" 
        14  // PADDLE DOWN KEY "K"
        );
  auto player_paddle_2 = std::make_unique<PlayerPaddle>(
        100.0f, 300.0f, 10.0f, 250.0f, 6.0f,
        game_window->m_game_renderer,
        keyboard_state,
        26, // PADDLE UP KEY "W" 
        22  // PADDLE DOWN KEY "S"
        );
  // Ball
  auto ball = std::make_unique<Ball>(
      800.0f-12.0f, 450.0f-12.0f, 24.0f, 24.0f, 6.0f, 
      game_window->m_game_renderer,
      game_window->GetWindowSizeY()
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
    player_paddle_2->drawSpriteToScreen();
    ball->m_current_direction = Ball::BallDirection::west;
    ball->drawSpriteToScreen();  

    // Exit the game with escape.
    if (keyboard_state [SDL_SCANCODE_ESCAPE]) {
      finished_running = true; 
    }

    // GAME LOGIC
    player_paddle_1->moveAndGlideSprite();
    player_paddle_2->moveAndGlideSprite();
    ball->moveAndGlideSprite();
    // Game logic here: 
      // Present backbuffer
      SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
