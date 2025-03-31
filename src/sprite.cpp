#include "sprite.h"
#include <SDL3/SDL_render.h>

// CONSTRUCTOR
Sprite::Sprite(float pos_x, float pos_y, float size_x, float size_y, int color_r, int color_g, int color_b, int color_a, SDL_Renderer* renderer)
  : m_pos_x { pos_x }, m_pos_y { pos_y }, m_size_x { size_x }, m_size_y { size_y }, m_color_r { color_r }, m_color_g { color_g }, m_color_b { color_b }, m_color_a { color_a }, m_renderer { renderer } {
    // Setting up SDL Rect 
    m_sprite = {
      m_pos_x,
      m_pos_y,
      m_size_x,
      m_size_y,
    };
  } 
Sprite::Sprite(float pos_x, float pos_y, float size_x, float size_y, SDL_Renderer* renderer) 
  : m_pos_x { pos_x }, m_pos_y { pos_y }, m_size_x { size_x }, m_size_y { size_y }, m_renderer { renderer } {
      m_sprite = {
        m_pos_x,
        m_pos_y,
        m_size_x,
        m_size_y,
      };
  }
void Sprite::colorSprite() {
  SDL_SetRenderDrawColor(m_renderer,m_color_r, m_color_g, m_color_b, m_color_a);
  SDL_RenderFillRect(m_renderer, &m_sprite);
}
