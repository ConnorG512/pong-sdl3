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
void Ball::moveBall() {
 switch (m_current_ball_direction) {
   case BallDirection::north:
    m_sprite.moveSpriteYPos(m_movement.m_movement_speed_y_pos);
    break;

   case BallDirection::northeast:
    m_sprite.moveSpriteYPos(m_movement.m_movement_speed_y_pos);
    m_sprite.moveSpriteXPos(m_movement.m_movement_speed_x_pos);
    break;

   case BallDirection::east:
    m_sprite.moveSpriteXPos(m_movement.m_movement_speed_x_pos);
    break;

   case BallDirection::southeast:
    m_sprite.moveSpriteYNeg(m_movement.m_movement_speed_y_neg);
    m_sprite.moveSpriteXPos(m_movement.m_movement_speed_x_pos);
    break;
   
   case BallDirection::south:
    m_sprite.moveSpriteYNeg(m_movement.m_movement_speed_y_neg);
    break;
   
   case BallDirection::southwest:
    m_sprite.moveSpriteYNeg(m_movement.m_movement_speed_y_neg);
    m_sprite.moveSpriteXNeg(m_movement.m_movement_speed_x_neg);
    break;
   
   case BallDirection::west:
    m_sprite.moveSpriteXNeg(m_movement.m_movement_speed_x_neg);
    break;
   
   case BallDirection::northwest:
    m_sprite.moveSpriteYPos(m_movement.m_movement_speed_y_pos);
    m_sprite.moveSpriteXNeg(m_movement.m_movement_speed_x_neg);
    break;
 } 
}
void Ball::startInitialMovement(const int& player_one_score, const int& player_two_score) {
  if (player_one_score == player_two_score) {
    // Generate a random number from 0-1
    const int random_number = rand() % 2;

    if (random_number == 0) {
    m_current_ball_direction = BallDirection::east;
    }
    else if (random_number == 1) {
    m_current_ball_direction = BallDirection::west;
    }
  } 
  else if (player_one_score >= player_two_score) {
    m_current_ball_direction = BallDirection::east;
  }
  else if (player_one_score <= player_two_score) {
    m_current_ball_direction = BallDirection::west;
  }
}
