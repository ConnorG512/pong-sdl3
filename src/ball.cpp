#include "ball.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
// CONSTRUCTOR
Ball::Ball(float position_x, float position_y, float size_x, float size_y, SDL_Renderer* renderer) 
  : m_sprite (position_x, position_y, size_x, size_y, renderer)
  , m_movement(4, 4 ,4 ,4) {
}
void Ball::drawSpriteOnScreen() {
  m_sprite.colorSprite();
}
void Ball::moveYPos() {
  m_sprite.moveSpriteYPos(m_movement.GetYPosMovementSpeed());
}
void Ball::moveYNeg() {
  m_sprite.moveSpriteYNeg(m_movement.GetYNegMovementSpeed());
}
void Ball::moveXPos() {
  m_sprite.moveSpriteXPos(m_movement.GetXPosMovementSpeed());
}
void Ball::moveXNeg() {
  m_sprite.moveSpriteXNeg(m_movement.GetXNegMovementSpeed());
}
void Ball::startInitialMovement(const int& player_one_score, const int& player_two_score) {
  if (player_one_score == player_two_score) {
    // Generate a random number from 0-1
    const int random_number = rand() % 2;

    if (random_number == 0) {
    m_sprite.moveSpriteXNeg(m_movement.GetXNegMovementSpeed());
    }
    else if (random_number == 1) {
    m_sprite.moveSpriteXPos(m_movement.GetXPosMovementSpeed());
    }
  } 
  else if (player_one_score >= player_two_score) {
    m_sprite.moveSpriteXNeg(m_movement.GetXNegMovementSpeed());
  }
  else if (player_one_score <= player_two_score) {
    m_sprite.moveSpriteXPos(m_movement.GetXPosMovementSpeed());
  }
}
