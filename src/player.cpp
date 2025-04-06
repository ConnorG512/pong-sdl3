#include "player.h"
#include <cstdio>

Player::Player(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer) 
  : m_sprite(position_x, position_y, size_x, size_y, renderer)
  , m_score() 
  , m_movement(8, 8, 8, 8) {
}
void Player::colorSprite() {
  m_sprite.colorSprite();
}
void Player::moveYPos() {
  m_sprite.moveSpriteYPos(m_movement.m_movement_speed_y_pos);
}
void Player::moveYNeg() {
  m_sprite.moveSpriteYNeg(m_movement.m_movement_speed_y_neg);
}
void Player::addToPlayerScore(const int score_to_add) {
  m_score.increaseScore(score_to_add);
}
void Player::removeFromPlayerScore(const int score_to_remove) {
  m_score.reduceScore(score_to_remove);
}
const int& Player::GetPlayerScore() {
  return m_score.getCurrentScore();
}
