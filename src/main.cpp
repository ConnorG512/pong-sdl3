#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_keyboard.h>
#include <ostream>
#include <thread>

#include "ball.h"
#include "game_window.h"
#include "player_paddle.h"
#include "sdl_error_util.h"
#include "gamestate.h"

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

  // Setting the initial game state
  static GameState current_gamestate = GameState::kickoff;
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
    ball->drawSpriteToScreen();  

    // Exit the game with escape.
    if (keyboard_state [SDL_SCANCODE_ESCAPE]) {
      finished_running = true; 
    }

    // GAME LOGIC
    switch (current_gamestate) {
      case GameState::kickoff:
        // Position ball in the centre of the screen.
        ball->setSpriteInitialPosition(800 - 12, 450 - 12);  
        int random_number; 
        // Choose a kickoff direction 
        srand(time(0));
        random_number = rand() % 2;
        switch (random_number) {
          case 0:
            ball->m_current_direction = Ball::BallDirection::east;
            break;
          case 1:
            ball->m_current_direction = Ball::BallDirection::west;
            break;
        }
        current_gamestate = GameState::ingame;
        break;
      
      case GameState::ingame:
        player_paddle_1->moveAndGlideSprite();
        player_paddle_2->moveAndGlideSprite();
        ball->moveAndGlideSprite();

        // Check to see if the ball has hit either end of the screen. 

        break;
      case GameState::finished:
        // TODO 
        printf("Finished called!");
        // Exit the game
        finished_running = true;
        break;
    }
    // Present backbuffer
    SDL_RenderPresent(game_window->m_game_renderer); 
  }
  return 0;
}
