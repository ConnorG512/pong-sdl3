#ifndef SPRITE_H
#define SPRITE_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

class Sprite {
  private:
  SDL_FRect m_sprite;
  int m_color_r = 255;
  int m_color_g = 255;
  int m_color_b = 255;
  int m_color_a = 255;
  SDL_Renderer* m_renderer;
  
  // Methods
  void createRectangle();
  public:

  void moveSpriteYPos(const float* p_movement_speed);
  void moveSpriteYNeg(const float* p_movement_speed);
  void moveSpriteXPos(const float* p_movement_speed);
  void moveSpriteXNeg(const float* p_movement_speed);
  void colorSprite();

  // CONSTRUCTOR
  // Colors will default to bright white
  Sprite(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer);
};

#endif // SPRITE_H
