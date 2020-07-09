#ifndef GAME_H
#define GAME_H

#include <random>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  static constexpr int kNumOfPoisons = 4;
  Game(std::size_t grid_width, std::size_t grid_height);

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  void Update(); 
  void PlaceFood();
  void PlacePoisonousFoods();
  bool FoodCell(int x, int y) const;

  Snake snake_;
  SDL_Point food_;
  std::vector<SDL_Point> poisons_;

  std::random_device dev_;
  std::mt19937 engine_;
  std::uniform_int_distribution<int> random_w_;
  std::uniform_int_distribution<int> random_h_;

  int score_{0};
};

#endif
