#ifndef SPRITE_H
#define SPRITE_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>
#include <cstdint>

class Sprite {
  // VARIABLES
  protected:
  SDL_FRect m_sprite;
  SDL_Renderer* m_renderer;
  const std::uint8_t m_color_r { 255 };
  const std::uint8_t m_color_g { 255 };
  const std::uint8_t m_color_b { 255 };
  const std::uint8_t m_color_a { 255 };
  
  // MEMBER FUNCTIONS
  public:
  Sprite(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer);
  void drawSpriteToScreen() const ;
  void setSpritePosition(const int x_position, const int y_position);
};

#endif // SPRITE_H
