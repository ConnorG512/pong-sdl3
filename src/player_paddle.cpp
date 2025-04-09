#include "player_paddle.h"
#include <SDL3/SDL_scancode.h>
#include <cassert>
#include <cstdint>

PlayerPaddle::PlayerPaddle(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer,
    const bool* keyboard_state, std::uint8_t paddle_up_key, std::uint8_t paddle_down_key) 
  : Sprite(position_x, position_y, size_x, size_y, movement_speed, renderer) // Calls the constructor of the base class.
  , m_keyboard_state { keyboard_state }
  , m_paddle_up_key { paddle_up_key }
  , m_paddle_down_key { paddle_down_key} {
  }

void PlayerPaddle::moveAndGlideSprite() {
  assert(m_keyboard_state && "m_keyboard_state should not be a nullptr, pointer to SDL_GetKeyboardState is needed.");
  if (m_keyboard_state [m_paddle_up_key]) {
    m_sprite.y -= m_movement_speed;
  } else if (m_keyboard_state [m_paddle_down_key]) {
    m_sprite.y += m_movement_speed;
  }
}
void PlayerPaddle::IncreasePlayerScore(int score_to_add = 1) {
  int current_score_result = m_current_score += score_to_add;
}
