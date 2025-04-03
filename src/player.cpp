#include "player.h"
#include <cstdio>

Player::Player(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer) 
  : m_sprite(position_x, position_y, size_x, size_y, renderer)
  , m_score() 
  , m_movement(1, 1, 1, 1) {
}
void Player::colorSprite() {
  m_sprite.colorSprite();
}
void Player::moveYPos() {
  m_sprite.moveSpriteYPos(m_movement.GetYPosMovementSpeed());
}
