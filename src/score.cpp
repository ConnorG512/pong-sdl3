#include "score.h"
#include <cstdio>

void Score::increaseScore(const int scoreToAdd = 1) {
  m_current_score += scoreToAdd;
  printf("Score added! %d\n", m_current_score);
}
void Score::reduceScore(const int scoreToReduce = 1) {
  m_current_score -= scoreToReduce;
}
bool Score::CheckForMaximumScore() {
  if (m_current_score >= m_maximum_score) {
    return true;
  }
  return false;
}
const int& Score::getCurrentScore() {
  return m_current_score;
}
