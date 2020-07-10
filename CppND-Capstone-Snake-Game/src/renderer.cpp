#include "renderer.h"

#include <iostream>
#include <sstream>
#include <iomanip>

Renderer::Renderer(std::size_t screen_width, std::size_t screen_height,
                   std::size_t grid_width, std::size_t grid_height)
    : screen_width_(screen_width),
      screen_height_(screen_height),
      grid_width_(grid_width),
      grid_height_(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

void Renderer::Render(Snake const &snake, SDL_Point const &food, const std::vector<SDL_Point> &poisons) {
  SDL_Rect block;
  block.w = screen_width_ / grid_width_;
  block.h = screen_height_ / grid_height_;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer_);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer_, &block);

  // Render poisonous foods
  SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0x00, 0x00, 0xFF);
  for (auto &poison : poisons) {
    block.x = poison.x * block.w;
    block.y = poison.y * block.h;
    SDL_RenderFillRect(sdl_renderer_, &block);
  }

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer_, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer_, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xA5, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer_, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer_);
}

void Renderer::UpdateWindowTitle(int score, int fps, int snake_size, long elapsed_time) {
  std::ostringstream title; 
  title << "Score: " << score << "  Size: " << snake_size << "  Elapsed time: " 
      << std::setw(2) << static_cast<float>(elapsed_time) / 1000 << " s" << "  FPS: " << fps;
  SDL_SetWindowTitle(sdl_window_, title.str().c_str());
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window_);
  SDL_Quit();
}

