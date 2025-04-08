#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H

#include "sprite.h"
#include <cstdint>
class PlayerPaddle : public Sprite {
  //////////////////////
  // MEMBER VARIABLES 
  //////////////////////   
  private:
    const bool* m_keyboard_state { nullptr };
    const std::uint8_t m_paddle_up_key {}; 
    const std::uint8_t m_paddle_down_key {}; 
    const int m_maximum_score { 3 };
  public:
    int m_current_score { 0 };
  
  //////////////////////
  // MEMBER FUNCTIONS
  //////////////////////   
  public:
  PlayerPaddle(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer, 
      const bool* keyboard_state, const std::uint8_t paddle_up_key, const std::uint8_t paddle_down_key);
  void moveAndGlideSprite() override;   
  private:
    void IncreasePlayerScore(int score_to_add); 
    bool CheckForGameWin() const;
};

#endif // !PLAYER_PADDLE_H
