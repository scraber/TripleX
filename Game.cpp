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

  while (lives) {
    /* read input for guesses */
    int guess_a, guess_b, guess_c;
    std::cin >> guess_a >> guess_b >> guess_c;

    /* check if all 3 inputs are valid */
    if (((guess_a == secret_a) || (guess_a == secret_b) ||
         (guess_a == secret_c)) &&
        ((guess_b == secret_a) || (guess_b == secret_b) ||
         (guess_b == secret_c)) &&
        ((guess_c == secret_a) || (guess_c == secret_b) ||
         (guess_c == secret_c))) {
      std::cout << "Congrats, you can proceed further" << std::endl;
      std::cout << "---------------------------------" << std::endl;
      difficulty++;
      break;
    }
    /* otherwise decrease lives */
    else {
      lives--;
      std::cout << "Wrong combination" << std::endl
                << "You have " << unsigned(lives) << " attempts left!"
                << std::endl;
    }
  }
}