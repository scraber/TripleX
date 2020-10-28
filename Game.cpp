#include "Game.h"

#include <algorithm> /* find */
#include <cstdlib>   /* srand, rand */
#include <ctime>
#include <iostream>
#include <vector>

void PlayGameDifficulty(std::uint8_t& Difficulty, std::uint8_t& Lives) {
  std::cout << "LEVEL: " << unsigned(Difficulty) << std::endl << std::endl;

  int SecretA, SecretB, SecretC;

  /* random seed: */
  srand(time(NULL));

  /* generate secret variables */
  SecretA = rand() % Difficulty + Difficulty;
  SecretB = rand() % Difficulty + Difficulty;
  SecretC = rand() % Difficulty + Difficulty;

  std::vector<int> Secrets{SecretA, SecretB, SecretC};

  /* generate hints */
  int HintAdd = SecretA + SecretB + SecretC;
  int HintMultiply = SecretA * SecretB * SecretC;

  std::cout << "Sum of secret numbers is equal to: " << HintAdd << std::endl;
  std::cout << "Product of secret numbers is equal to: " << HintMultiply
            << std::endl;

  while (Lives) {
    /* read input for Guesses */
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    std::vector<int> Guesses{GuessA, GuessB, GuessC};

    ///* check if all 3 inputs are valid */
    // if (((GuessA == SecretA) || (GuessA == SecretB) ||
    //     (GuessA == SecretC)) &&
    //    ((GuessB == SecretA) || (GuessB == SecretB) ||
    //     (GuessB == SecretC)) &&
    //    ((GuessC == SecretA) || (GuessC == SecretB) ||
    //     (GuessC == SecretC))) {
    //  std::cout << "Congrats, you can proceed further" << std::endl;
    //  std::cout << "---------------------------------" << std::endl;
    //  Difficulty++;
    //  break;
    //}
    ///* otherwise decrease Lives */
    // else {
    //  Lives--;
    //  std::cout << "Wrong combination" << std::endl
    //            << "You have " << unsigned(Lives) << " attempts left!"
    //            << std::endl;
    //}

    bool Pass = true;
    /* helper vector used to copy original values after removing some elements
     * and failing at Guesses */
    std::vector<int> SecretAttempts = Secrets;
    /* iterate over Guesses vector and check if its elements are within SecretsAttempts
     * vector */
    for (auto& entry : Guesses) {
      std::vector<int>::iterator FoundElement =
          std::find(SecretAttempts.begin(), SecretAttempts.end(), entry);

      if (FoundElement != SecretAttempts.end()) {
        /* delete found element from Secrets vector */
        SecretAttempts.erase(FoundElement);
      } else {
        Pass = false;
        break;
      }
    }

    if (Pass) {
      std::cout << "Congrats, you can proceed further" << std::endl;
      std::cout << "---------------------------------" << std::endl;
      Difficulty++;
      break;
    } else {
      Lives--;
      std::cout << "Wrong combination" << std::endl
                << "You have " << unsigned(Lives) << " attempts left!"
                << std::endl;
    }
  }
}