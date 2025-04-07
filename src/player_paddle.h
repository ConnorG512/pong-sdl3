#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H

#include "sprite.h"
class PlayerPaddle : public Sprite {
  // MEMBER VARIABLES
  protected:
    const bool* m_keyboard_state { nullptr };
  // MEMBER FUNCTIONS
  public:
  PlayerPaddle();
  void movePlayer();  
};

#endif // !PLAYER_PADDLE_H
