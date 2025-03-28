#include "game_window.h"

// Public
// CONSTRUCTOR
GameWindow::GameWindow(const std::string& window_title, const int window_size_x, const int window_size_y)
  : m_window_title { window_title }, m_window_size_x { window_size_x }, m_window_size_y { window_size_y} {
    createWindow();
    SDLError::SDLPrintError(m_game_window, "sdl_window.cpp");
  }
// DESTRUCTOR
GameWindow::~GameWindow() {
  SDL_DestroyWindow(m_game_window);
  SDL_Quit();
}

// Private
void GameWindow::createWindow() {
  m_game_window = SDL_CreateWindow(m_window_title.c_str(), m_window_size_x, m_window_size_y, 0);
}
