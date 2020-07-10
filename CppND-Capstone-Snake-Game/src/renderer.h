#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(std::size_t screen_width, std::size_t screen_height,
           std::size_t grid_width, std::size_t grid_height);

  void Render(Snake const &snake, SDL_Point const &food, const std::vector<SDL_Point> &poisons);
  void UpdateWindowTitle(int score, int fps, int snake_size);

  ~Renderer();

 private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
  const std::size_t grid_width_;
  const std::size_t grid_height_;
};

#endif
