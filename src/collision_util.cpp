#include "collision_util.h"
#include <SDL3/SDL_rect.h>

bool Collision::checkForTwoRectCollision(const SDL_FRect& object_a, const SDL_FRect& object_b) {
  return (object_a.x < object_b.x + object_b.w &&
      object_a.x + object_a.w > object_b.x && 
      object_a.y < object_b.y + object_b.h && 
      object_a.y + object_a.h > object_b.y);
}
bool Collision::checkForSingleValueCollisionHigherThan(const float object_position, const int value) {
  return object_position >= value;
}
bool Collision::checkForSingleValueCollisionLowerThan(const float object_position, const int value) {
  return object_position <= value;
}

