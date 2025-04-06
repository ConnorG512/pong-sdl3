#include "sprite.h"
#include "movement.h"
#include <SDL3/SDL_render.h>

class Ball {
  // Variables
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

  private:
    Sprite m_sprite;
    Movement m_movement;
  public:
    BallDirection m_current_ball_direction;
  
  // Member Functions
  private:

  public:
    // CONSTRUCTOR 
    Ball(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer); 
    // Draw the sprite on screen based on the constructor parameters.
    void drawSpriteOnScreen();
    void moveBall();
    
    // Move toward the specific player depending on which one has the least score
    // The lower score player will have priority over the ball coming towards them.
    // If both players have equal score, then the balls direction of choice will be random.
    void startInitialMovement(const int& player_one_score, const int& player_two_score);
};
