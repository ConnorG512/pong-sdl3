#include <SDL3/SDL_video.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

#include "sdl_error_util.h"

class GameWindow {
  private:
    // Variables
    SDL_Window *m_game_window;
    std::string m_window_title;
    const int m_window_size_x;
    const int m_window_size_y;
    bool m_done { false };

    //METHOD
    // Create the window with the title, x resolution and y resolution.
    void createWindow();

  public:
    // CONSTRUCTOR
    // Expects the window tite x resolution and y resolution to be passed. Will create the window on construct.
    GameWindow(const std::string& window_title, const int window_size_x, const int window_size_y);
    // DESTRUCTOR
    // Will Destroy the window and quit SDL
    ~GameWindow();
};
