#include "game.h"
#include <iostream>
#include "SDL.h"

void audio_callback(void *user_data, uint8_t *stream, int stream_length) {
  AudioData *audio = static_cast<AudioData *>(user_data);

  if (audio->length == 0) return;

  uint32_t length = static_cast<uint32_t>(stream_length);
  length = (length > audio->length) ? audio->length : length;
  SDL_memcpy(stream, audio->pos, length);
  audio->pos += length;
  audio->length -= length;
}

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake_(grid_width, grid_height),
      engine_(dev_()),
      random_w_(0, static_cast<int>(grid_width) - 1),
      random_h_(0, static_cast<int>(grid_height) - 1) {
  PlaceFood();
  
  poisons_.resize(kNumOfPoisons);
  PlacePoisonousFoods();

  AudioSetup();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  SDL_PauseAudioDevice(sdl_audio_, 0);
 
  while (running) {
    frame_start = SDL_GetTicks();

    if (audio_.length == 0) {
        AudioSetup();
    }

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake_);
    Update();
    renderer.Render(snake_, food_, poisons_);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score_, frame_count, snake_.size);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

int Game::GetScore() const { return score_; }

int Game::GetSize() const { return snake_.size; }

Game::~Game() {
    SDL_CloseAudioDevice(sdl_audio_);
    SDL_FreeWAV(wav_start_);
}

void Game::Update() {
  if (!snake_.alive) return;

  snake_.Update();

  int new_x = static_cast<int>(snake_.head_x);
  int new_y = static_cast<int>(snake_.head_y);

  // Check if snake ate any poison.
  for (int i = 0; i < kNumOfPoisons; ++i) {
      if (new_x == poisons_[i].x && new_y == poisons_[i].y) {
        snake_.alive = false;
        return;  
      }
  }
  
  // Check if there's food over here.
  if (food_.x == new_x && food_.y == new_y) {
    score_++;
    PlaceFood();
    PlacePoisonousFoods();

    // Grow snake and increase speed.
    snake_.GrowBody();
    snake_.speed += 0.01;
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w_(engine_);
    y = random_h_(engine_);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake_.SnakeCell(x, y)) {
      food_.x = x;
      food_.y = y;
      std::cout << "Placed food at x = " << x << " and y = " << y << std::endl; 
      return;
    }
  }
}

void Game::PlacePoisonousFoods() {
    poisons_.clear();
    int counter = 0;
    while (counter < kNumOfPoisons) {
        int x = random_w_(engine_);
        int y = random_h_(engine_);

        if (!snake_.SnakeCell(x, y) && !FoodCell(x, y) ) {
            poisons_.emplace_back(SDL_Point{x, y});
            ++counter;
        }
    }
}

bool Game::FoodCell(int x, int y) const {
    return x == food_.x && y == food_.y;
}

bool Game::AudioSetup() {
  if (SDL_LoadWAV(wav_path_.c_str(), &wav_spec_, &wav_start_, &wav_length_) == nullptr) {
      std::cerr << "Error: file could not be loaded as an audio file." << std::endl;
      return false;
  }

  audio_.pos = wav_start_;
  audio_.length = wav_length_;

  wav_spec_.callback = audio_callback;
  wav_spec_.userdata = &audio_;

  sdl_audio_ = SDL_OpenAudioDevice(nullptr, 0, &wav_spec_, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
  
  if (sdl_audio_ == 0) {
      std::cerr << "Error: " << SDL_GetError() << std::endl;
      return false;
  }

  return true;
}
