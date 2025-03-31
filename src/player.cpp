#include "player.h"

Player::Player(int pos_x, int pos_y, const int size_x, const int size_y, SDL_Renderer* renderer) 
  : m_sprite(100, 300, 10, 300, renderer)
  , m_score() {
  }
void Player::colorSprite() {
  m_sprite.colorSprite();
}

