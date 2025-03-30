#include "divider.h"
#include <SDL3/SDL_render.h>

Divider::Divider(SDL_Renderer* renderer) 
  : m_sprite_0(0, 0, 250, 250, 0, 255, 255, 0, renderer) {

  }

void Divider::drawDividerOnScreen() {
  m_sprite_0.colorSprite();
}
