#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>

void printHeader() {
  std::cout
    << "=====================================================\n"
    << "= SIMPLE ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =\n"
    << "=====================================================\n";
}

int getInt(const std::string& promt, in min = INT_MIN, int max = INT_MAX) {
  int value;

  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      if (value >= min && value <= max)
        return value;
      else
        std::cout << "Value out of range [" << min << "-" << max << "]!\n";
    }
    else {
      std::cout << "Invalid input!\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }
}

void generateRandomNumbers() {
  const int max_amount 1000000;
  const int max_lenght = 10;

  int amount_digits = getInt("Enter amount of random digits: ", 1, max_amount);
  int lenght_digits = getInt("Enter max lenght of number: ", 1, max_lenght);

  int *numbers = new int[amount_digits];

  int power = (int)pow(10, lenght_digits);
}

void saveToFile(int* numbers, int size) {

}

int main() {
  srand((unsigned int)time(nullptr));
  printHeader();
  generateRandomNumbers()

	return 0;
}
