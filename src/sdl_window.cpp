#include "sdl_window.h"

// Public
// CONSTRUCTOR
GameWindow::GameWindow(const std::string& window_title, const int window_size_x, const int window_size_y)
  : m_window_title { window_title }, m_window_size_x { window_size_x }, m_window_size_y { window_size_y} {
    createWindow();
    checkForWindowError();
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
void GameWindow::checkForWindowError(){
  if (m_game_window == nullptr) {
    std::cout << "Failed to create SDL window! Error: " << SDL_GetError() << std::endl;
    exit(1);
  }
}
