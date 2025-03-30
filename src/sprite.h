#ifndef SPRITE_H
#define SPRITE_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

class Sprite {
  private:
  float m_pos_x; 
  float m_pos_y;
  float m_size_x;
  float m_size_y;
  int m_color_r;
  int m_color_g;
  int m_color_b;
  int m_color_a;
  SDL_FRect m_sprite;
  SDL_Renderer* m_renderer;
  
  // Methods
  void createRectangle();
  public:

  void colorSprite();
  // CONSTRUCTOR
  Sprite(float pos_x, float pos_y, float size_x, float size_y, int color_r, int color_g, int color_b, int color_a, SDL_Renderer* renderer);
};

#endif // SPRITE_H
