#ifndef SPRITE_H
#define SPRITE_H

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>
#include <cstdint>

class Sprite {
  public:
    SDL_FRect m_sprite;
  protected:
    SDL_Renderer* m_renderer { nullptr };
    static constexpr std::uint8_t m_color_r { 255 };
    static constexpr std::uint8_t m_color_g { 255 };
    static constexpr std::uint8_t m_color_b { 255 };
    static constexpr std::uint8_t m_color_a { 255 };
    const float m_movement_speed { 6 };

  public:
  Sprite(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer);
  void drawSpriteToScreen() const ;
  // Sets or teleports a sprite to a set x and y position.
  void setSpriteInitialPosition(const int x_position, const int y_position);
  virtual void moveAndGlideSprite() = 0; // Pure virtual function to be implemented in player_paddle and ball.
};

#endif // SPRITE_H
