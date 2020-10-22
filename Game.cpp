#include "Game.h"

#include <cstdlib> /* srand, rand */
#include <ctime>
#include <iostream>

void PlayGameDifficulty(std::uint8_t& difficulty, std::uint8_t& lives) {
  std::cout << "LEVEL: " << unsigned(difficulty) << std::endl << std::endl;

  std::uint8_t secret_a, secret_b, secret_c;

  /* random seed: */
  srand(time(NULL));

  /* generate secret variables */
  secret_a = rand() % difficulty + difficulty;
  secret_b = rand() % difficulty + difficulty;
  secret_c = rand() % difficulty + difficulty;

  /* generate hints */
  int hint_add = secret_a + secret_b + secret_c;
  int hint_multiply = secret_a * secret_b * secret_c;

  std::cout << "Sum of secret numbers is equal to: " << hint_add << std::endl;
  std::cout << "Product of secret numbers is equal to: " << hint_multiply
            << std::endl;

  /* read input for guesses */
  int a, b, c;
  std::cin >> a >> b >> c;
}