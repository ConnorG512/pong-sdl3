#include "ball.h"
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
