#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"

#include <vector>

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width_(grid_width),
        grid_height_(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y) const;
  
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  
  Direction direction = Direction::kUp;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(const SDL_Point &current_cell, const SDL_Point &prev_cell);

  bool growing_{false};
  const int grid_width_;
  const int grid_height_;
};

#endif
