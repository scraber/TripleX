#include <cstdint>
#include <iostream>
#include <string>

#include "Game.h"

int main() {
  std::uint8_t difficulty = 1;
  std::uint8_t max_difficulty = 3;
  std::uint8_t lives = 3;
  while (lives && !(difficulty-1 == max_difficulty)) {
    PlayGameDifficulty(difficulty, lives);
  }

  std::string msg = (lives == 0) ? "lost!" : "won!";

  std::cout << "You've " << msg << std::endl;
}
