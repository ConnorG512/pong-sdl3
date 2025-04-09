#include "ball.h"
#include <cassert>
#include <cstdio>

Ball::Ball(float position_x, float position_y, float size_x, float size_y, float movement_speed, SDL_Renderer* renderer, 
    const int screen_width)
  : Sprite(position_x, position_y, size_x, size_y, movement_speed, renderer) {
  } 

void Ball::moveAndGlideSprite() {
  switch (m_current_direction) {
    case BallDirection::north:
      m_sprite.y -= m_movement_speed;
      break;
    case BallDirection::northeast:
      m_sprite.y -= m_movement_speed; 
      m_sprite.x += m_movement_speed; 
      break;
    case BallDirection::east: 
      m_sprite.x += m_movement_speed; 
      break;
    case BallDirection::southeast: 
      m_sprite.y += m_movement_speed;
      m_sprite.x += m_movement_speed; 
      break;
    case BallDirection::south: 
      m_sprite.y += m_movement_speed;
      break;
    case BallDirection::southwest: 
      m_sprite.y += m_movement_speed;
      m_sprite.x -= m_movement_speed;
      break;
    case BallDirection::west: 
      m_sprite.x -= m_movement_speed;
      break;
    case BallDirection::northwest: 
      m_sprite.y -= m_movement_speed;
      m_sprite.x -= m_movement_speed;
      break;
  } 
}
