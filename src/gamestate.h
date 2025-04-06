#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState {
  kickoff,  // Initial start of the game and when a score has been made.
  ingame,   // standard gameplay, players have control of their paddles.
  finished, // completed game. No control.
};

#endif // !GAMESTATE_H
