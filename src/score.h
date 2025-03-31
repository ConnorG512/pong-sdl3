#ifndef SCORE_H
#define SCORE_H

class Score{
  private:
    int m_current_score { 0 };
    const int m_maximum_score { 5 };

    // Methods
    void increaseScore(const int scoreToAdd);
    bool CheckForMaximumScore();
};

#endif // !SCORE_H
