#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "score.h"
#include "movement.h"

#include <SDL3/SDL_render.h>

class Player{
  private:
    Sprite m_sprite;
    Score m_score;
  public:
    Movement m_movement;
    Player(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer); 
    // SPRITE
    void colorSprite();
    // MOVEMENT 
    void moveYPos();
    void moveYNeg();
};

#endif
