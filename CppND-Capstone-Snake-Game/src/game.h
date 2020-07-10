#ifndef GAME_H
#define GAME_H

#include <random>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

struct AudioData {
  uint8_t *pos;
  uint32_t length; 
};

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  ~Game();

 private:
  static constexpr int kNumOfPoisons = 4;
  static constexpr long kBonusTimePeriod_ms = 20000;
  
  void Update(); 
  bool CellAvailable(int x, int y) const;
  void PlaceFood();
  void PlacePoisonousFoods();
  void PlaceBonus();
  bool FoodCell(int x, int y) const;
  bool PoisonCell(int x, int y) const;
  bool AudioSetup();

  Snake snake_;
  SDL_Point food_;
  std::vector<SDL_Point> poisons_;
  SDL_Point bonus_;
  SDL_Point jem_;

  std::random_device dev_;
  std::mt19937 engine_;
  std::uniform_int_distribution<int> random_w_;
  std::uniform_int_distribution<int> random_h_;

  int score_ = 0;
  long elapsed_time_ = 0;
  long last_bonus_time_ = 0;

  std::string wav_path_ = "../example.wav";
  uint8_t* wav_start_;
  uint32_t wav_length_;
  SDL_AudioDeviceID sdl_audio_;
  SDL_AudioSpec wav_spec_;
  AudioData audio_;
};

#endif
