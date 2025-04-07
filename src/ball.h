#ifndef BALL_H 
#define BALL_H

#include "sprite.h"
class Ball : public Sprite {
  //////////////////////
  // TYPE DEFINITIONS 
  //////////////////////
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

  //////////////////////
  // MEMBER VARIABLES 
  //////////////////////
  public: 
    BallDirection m_current_direction {};
  private:
  const int* m_window_width {nullptr};

  //////////////////////
  // MEMBER FUNCTIONS
  //////////////////////
  public:
    Ball(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer);
    void moveAndGlideSprite() override; 
  private:
};

#endif // !BALL_H 
