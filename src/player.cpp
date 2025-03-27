#include "player.h"

int Player::addToPlayerScore(int& score_to_add) {
  m_current_score += score_to_add;
  return m_current_score;
}
