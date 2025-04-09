#ifndef BALL_H 
#define BALL_H

#include "sprite.h"
class Ball : public Sprite {
  public:
    enum class BallDirection {
        north,
        northeast,
        east,
        southeast,
        south,
        southwest,
        west,
        northwest,
      };

  public: 
    BallDirection m_current_direction {};
  private:
  const int m_window_width { 0 };

  public:
    Ball(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer,
        const int screen_width);
    void moveAndGlideSprite() override;
};

#endif // !BALL_H 
