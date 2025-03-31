#include "score.h"

void Score::increaseScore(const int scoreToAdd = 1) {
  m_current_score += scoreToAdd;
}
bool Score::CheckForMaximumScore() {
  if (m_current_score >= m_maximum_score) {
    return true;
  }
  return false;
}
