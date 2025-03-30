#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player{
  public:
    // Adds the specified amount to the player's score.
    int addToPlayerScore(int& score_to_add);
  private:
    int m_current_score;
    std::string m_player_name; 
};

#endif
