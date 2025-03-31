#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "score.h"
#include <SDL3/SDL_render.h>

class Player{
  private:
    Sprite m_sprite;
    Score m_score;
  public:
    Player(int pos_x, int pos_y, const int size_x, const int size_y, SDL_Renderer* renderer);
    void colorSprite();
};

#endif
