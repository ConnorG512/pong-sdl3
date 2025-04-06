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
#include "player.h"
#include "sdl_error_util.h"
#include "divider.h"
#include "gamestate.h"
#include "ball.h"

int main (int, char **) {
  bool finished_running { false };
  // Create a game window on heap memory.
  std::unique_ptr<GameWindow> game_window{ new GameWindow("Pong")};
  // Divider 
  std::unique_ptr<Divider> background_divider{ new Divider(game_window->m_game_renderer)};
  // Player creation
  std::unique_ptr<Player> player_paddle_1 { new Player(100, 300, 10, 300, game_window->m_game_renderer)};
  std::unique_ptr<Player> player_paddle_2 { new Player(1500, 300, 10 ,300, game_window->m_game_renderer)};
  // Ball creation 
  std::unique_ptr<Ball> ball { new Ball(800-12, 450-12, 24, 24, game_window->m_game_renderer)};

  // Get SDL Keyboard state
  const bool* keyboard_state = SDL_GetKeyboardState(nullptr);

  while (!finished_running) {  
    SDL_Event event;

    SDL_Delay(16);
    // Background colour
    SDL_SetRenderDrawColor(game_window->m_game_renderer, 0, 0, 0, 255);
    while (SDL_PollEvent(&event)) {  
    } 

    // Clear the backbuffer
    SDL_RenderClear(game_window->m_game_renderer);
    // Divider 
    background_divider->drawDividerOnScreen();
    // Player sprites
    player_paddle_1->colorSprite();
    player_paddle_2->colorSprite();
    
    // Ball logic
    ball->drawSpriteOnScreen();
    
    // Exit the game with escape.
    if (keyboard_state [SDL_SCANCODE_ESCAPE]) {
      finished_running = true; 
    }
    // GAME LOGIC
    // Start on the kickoff gamestate
    static GameState current_gamestate = GameState::kickoff;
    switch (current_gamestate) {

      case GameState::kickoff:
        ball->startInitialMovement(player_paddle_1->GetPlayerScore(), player_paddle_2->GetPlayerScore());
        current_gamestate = GameState::ingame;
        break;

      case GameState::ingame:
        // Player control
        if ( keyboard_state [SDL_SCANCODE_W]) {
          player_paddle_1->moveYPos();
        }
        if (keyboard_state [SDL_SCANCODE_S]) {
          player_paddle_1->moveYNeg();
        }
        if (keyboard_state [SDL_SCANCODE_I]) {
          player_paddle_2->moveYPos();
        }
        if (keyboard_state [SDL_SCANCODE_K]) {
          player_paddle_2->moveYNeg();
        }
        ball->moveBall();

        break;

      case GameState::finished:
        printf("Finished!");
        break;
    };

    // Game logic here: 
      // Present backbuffer
      SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
