#include <SDL3/SDL_rect.h>

namespace Collision {
  bool checkForTwoRectCollision(const SDL_FRect& object_a, const SDL_FRect& object_b);
  
  // Check for collision based on a single value, e.g. top / bottom of screen.
  bool checkForSingleValueCollisionHigherThan(const float& object_position, const int& value);
  bool checkForSingleValueCollisionLowerThan(const float& object_position, const int& value);
}
