#include <cstdint>
#include <iostream>
#include <string>

#include "Game.h"

int main() {
  std::uint8_t Difficulty = 1;
  std::uint8_t MaxDifficulty = 3;
  std::uint8_t Lives = 3;
  while (Lives && !(Difficulty-1 == MaxDifficulty)) {
    PlayGameDifficulty(Difficulty, Lives);
  }

  std::string msg = (Lives == 0) ? "lost!" : "won!";

  std::cout << "You've " << msg << std::endl;
}
