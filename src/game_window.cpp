#include "game_window.h"
#include <SDL3/SDL_render.h>

// Public
// CONSTRUCTOR
GameWindow::GameWindow(const std::string& window_title, const int window_size_x, const int window_size_y)
  : m_window_title { window_title }, m_window_size_x { window_size_x }, m_window_size_y { window_size_y} {
    createWindow();
    SDLError::SDLPrintError(m_game_window, "sdl_window.cpp");
    createRenderer();
    printf("Game window Address: %p \n", &m_game_window);
    printf("Game renderer Address: %p \n", &m_game_renderer);
    printf("Size X Address: %p \n", &m_window_size_x);
    printf("Size Y renderer Address: %p \n", &m_window_size_y);
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
void GameWindow::createRenderer() {
  m_game_renderer = SDL_CreateRenderer(m_game_window, nullptr);
}
