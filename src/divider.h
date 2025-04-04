#ifndef DIVIDER_H
#define DIVIDER_H

#include "sprite.h"

class Divider {
  public:
  // CONSTRUCTOR
  Divider(SDL_Renderer* renderer);
  // Draw all of the dividers to the screen.
  void drawDividerOnScreen();
  
  private:
  SDL_Renderer* m_renderer;
  Sprite m_sprite_0;
  Sprite m_sprite_1;
  Sprite m_sprite_2;
  Sprite m_sprite_3;
};

#endif // !DIVIDER_H
