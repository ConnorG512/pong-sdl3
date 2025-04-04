#include "game_window.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include "sdl_error_util.h"

// Public
// CONSTRUCTOR
GameWindow::GameWindow(const std::string& window_title)
  : m_window_title { window_title } {
    createWindow();
    SDLError::SDLPrintError(m_game_window, "sdl_window.cpp");
    createRenderer();
  }
// DESTRUCTOR
GameWindow::~GameWindow() {
  SDL_DestroyWindow(m_game_window);
  SDL_DestroyRenderer(m_game_renderer);
  SDL_Quit();
}
int GameWindow::GetWindowSizeX() {
  return m_window_size_x;
}
int GameWindow::GetWindowSizeY() {
  return m_window_size_y;
}

// Private
void GameWindow::createWindow() {
  m_game_window = SDL_CreateWindow(m_window_title.c_str(), m_window_size_x, m_window_size_y, SDL_WINDOW_KEYBOARD_GRABBED);
  SDLError::SDLPrintError(m_game_window, "src/game_window.cpp");
}
void GameWindow::createRenderer() {
  m_game_renderer = SDL_CreateRenderer(m_game_window, nullptr);
}
