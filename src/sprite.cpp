#include "sprite.h"
#include <SDL3/SDL_render.h>
#include <cassert>
#include <cstdio>

// CONSTRUCTOR
Sprite::Sprite(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer) 
  : m_sprite{position_x, position_y, size_x, size_y}
  , m_renderer(renderer) 
  , m_movement_speed { movement_speed } {
    assert(m_renderer && "\"m_renderer\" is null!"); 
  } 

void Sprite::drawSpriteToScreen() const {
  SDL_SetRenderDrawColor(m_renderer, m_color_r, m_color_g, m_color_b, m_color_a);
  SDL_RenderFillRect(m_renderer, &m_sprite);
}
void Sprite::setSpriteInitialPosition(const int x_position, const int y_position) {
  m_sprite.x = x_position;
  m_sprite.y = y_position;
}
float& Sprite::getBallXCoOrdinate() {
  return m_sprite.x;
}
float& Sprite::getBallYCoOrdinate() {
  return m_sprite.y;
}
