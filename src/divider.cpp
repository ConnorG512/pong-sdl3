#include "divider.h"
#include <SDL3/SDL_render.h>

Divider::Divider(SDL_Renderer* renderer) 
  : m_sprite_0(800, 0, 4, 216, 255, 255, 255, 255, renderer), 
    m_sprite_1(800, 228, 4, 216, 255, 255, 255, 255, renderer), 
    m_sprite_2(800, 456, 4, 216, 255, 255, 255, 255, renderer), 
    m_sprite_3(800, 684, 4, 216, 255, 255, 255, 255, renderer) {
  }

void Divider::drawDividerOnScreen() {
  m_sprite_0.colorSprite();
  m_sprite_1.colorSprite();
  m_sprite_2.colorSprite();
  m_sprite_3.colorSprite();
}
