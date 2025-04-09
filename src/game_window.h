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

class GameWindow {
  private:
    std::string m_window_title;
    bool m_done { false };
  public:
    SDL_Window *m_game_window;
    SDL_Renderer *m_game_renderer;
    static constexpr int m_window_size_x { 1600 };
    static constexpr int m_window_size_y { 900 };

  public:
    void createWindow();
    void createRenderer();
    // CONSTRUCTOR
    GameWindow(const std::string& window_title);
    ~GameWindow();
};

#endif // GAME_WINDOW_H
