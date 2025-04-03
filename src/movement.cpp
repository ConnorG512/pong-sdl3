#include "movement.h"
#include <cstdio>

Movement::Movement(const float move_speed_y_pos, const float move_speed_y_neg, const float move_speed_x_pos, const float move_speed_x_neg)
  : m_movement_speed_y_pos { move_speed_y_pos }, m_movement_speed_y_neg { move_speed_y_neg }, m_movement_speed_x_pos { move_speed_x_pos }, m_movement_speed_x_neg { move_speed_x_neg } {} 

const float* Movement::GetYPosMovementSpeed() {
  return &m_movement_speed_y_pos;
}
const float* Movement::GetYNegMovementSpeed() {
  return &m_movement_speed_y_neg;
}
