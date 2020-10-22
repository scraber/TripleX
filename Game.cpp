#include "Game.h"

#include <algorithm> /* find */
#include <cstdlib>   /* srand, rand */
#include <ctime>
#include <iostream>
#include <vector>

void PlayGameDifficulty(std::uint8_t& difficulty, std::uint8_t& lives) {
  std::cout << "LEVEL: " << unsigned(difficulty) << std::endl << std::endl;

  int secret_a, secret_b, secret_c;

  /* random seed: */
  srand(time(NULL));

  /* generate secret variables */
  secret_a = rand() % difficulty + difficulty;
  secret_b = rand() % difficulty + difficulty;
  secret_c = rand() % difficulty + difficulty;

  std::vector<int> secrets{secret_a, secret_b, secret_c};

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

    std::vector<int> guesses{guess_a, guess_b, guess_c};

    ///* check if all 3 inputs are valid */
    // if (((guess_a == secret_a) || (guess_a == secret_b) ||
    //     (guess_a == secret_c)) &&
    //    ((guess_b == secret_a) || (guess_b == secret_b) ||
    //     (guess_b == secret_c)) &&
    //    ((guess_c == secret_a) || (guess_c == secret_b) ||
    //     (guess_c == secret_c))) {
    //  std::cout << "Congrats, you can proceed further" << std::endl;
    //  std::cout << "---------------------------------" << std::endl;
    //  difficulty++;
    //  break;
    //}
    ///* otherwise decrease lives */
    // else {
    //  lives--;
    //  std::cout << "Wrong combination" << std::endl
    //            << "You have " << unsigned(lives) << " attempts left!"
    //            << std::endl;
    //}

    bool pass = true;
    /* helper vector used to copy original values after removing some elements
     * and failing at guesses */
    std::vector<int> secret_attempts = secrets;
    /* iterate over guesses vector and check if its elements are within secrets
     * vector */
    for (auto& entry : guesses) {
      std::vector<int>::iterator found_elem =
          std::find(secret_attempts.begin(), secret_attempts.end(), entry);

      if (found_elem != secret_attempts.end()) {
        /* delete found element from secrets vector */
        secret_attempts.erase(found_elem);
      } else {
        pass = false;
        break;
      }
    }

    if (pass) {
      std::cout << "Congrats, you can proceed further" << std::endl;
      std::cout << "---------------------------------" << std::endl;
      difficulty++;
      break;
    } else {
      lives--;
      std::cout << "Wrong combination" << std::endl
                << "You have " << unsigned(lives) << " attempts left!"
                << std::endl;
    }
  }
}