#include <cstdint>
#include <iostream>
#include <string>

#include "Game.h"

int main() {
  std::uint8_t difficulty = 1;
  std::uint8_t max_difficulty = 10;
  std::uint8_t lives = 3;
  while (lives or difficulty == max_difficulty) {
    PlayGameDifficulty(difficulty, lives);
  }

  std::string msg = (lives == 0) ? "lost!" : "won!";

  std::cout << "You've " << msg << std::endl;
}
