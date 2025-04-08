#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

#include "sdl_error_util.h"

class GameWindow {
  private:
    // Variables
    std::string m_window_title;
    const int m_window_size_x { 1600 };
    const int m_window_size_y { 900 };
    bool m_done { false };

    //METHOD
    // Create the window with the title, x resolution and y resolution.
    void createWindow();
    void createRenderer();

  public:
    SDL_Window *m_game_window;
    SDL_Renderer *m_game_renderer;
    const int* GetWindowSizeX();
    const int* GetWindowSizeY();
    // CONSTRUCTOR
    // Create a window with a titel 1600 x 900 is the default resoltution
    GameWindow(const std::string& window_title);
    // DESTRUCTOR
    // Will Destroy the window and quit SDL
    ~GameWindow();
};

#endif // GAME_WINDOW_H
