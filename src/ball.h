#include "sprite.h"
#include "movement.h"
#include <SDL3/SDL_render.h>

class Ball {
  // Variables
  private:
    Sprite m_sprite;
    Movement m_movement;
  public:
  
  // Member Functions
  private:

  public:
    // CONSTRUCTOR 
    Ball(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer); 
    void drawSpriteOnScreen();
    void moveYPos();
    void moveYNeg();
    void moveXPos();
    void moveXNeg();
};
