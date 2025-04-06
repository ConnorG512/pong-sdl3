#ifndef SCORE_H
#define SCORE_H

class Score{
  public:
  private:
    int m_current_score { 0 };
    const int m_maximum_score { 5 };

    // Methods
  public:
    const int& getCurrentScore();
    void increaseScore(const int scoreToAdd);
    void reduceScore(const int scoreToReduce);
    bool CheckForMaximumScore();
  
};

#endif // !SCORE_H
