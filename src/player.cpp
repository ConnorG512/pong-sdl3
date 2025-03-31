#include "player.h"

Player::Player(int pos_x, int pos_y, const int size_x, const int size_y, SDL_Renderer* renderer) 
  : m_sprite(pos_x, pos_y, size_x, size_y, renderer)
  , m_score() {
  }
void Player::colorSprite() {
  m_sprite.colorSprite();
}

