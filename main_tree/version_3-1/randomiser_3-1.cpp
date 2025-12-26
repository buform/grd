#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>
#include <climits>

void printHeader() {
	std::cout
		<< "=====================================================\n"
		<< "= SIMPLE ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =\n"
		<< "=====================================================\n";
}

int getInt(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) {
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

void saveToFile(int* numbers, int size) {
	std::string file_name = "return.txt";
	std::ofstream file(file_name);

	if (file.is_open()) {
		for (int i = 0; i < size; i++)
			file << numbers[i] << "\n";
		file.seekp(0, std::ios::end);
		long long size = file.tellp();
		std::cout << "The file is saved as " << file_name << ".\n";
		std::cout << size << " byte(s)\n";
	}

	else {
		std::cout << "ERROR - cannot open the file!\n";
	}

	file.close();
}

void generateRandomNumbers() {
	const int max_amount = 1000000;
	const int max_lenght = 10;

	int amount_digits = getInt("Enter amount of random digits: ", 1, max_amount);
	int lenght_digits = getInt("Enter max lenght of number: ", 1, max_lenght);

	int *numbers = new int[amount_digits];
	int power = (int)pow(10, lenght_digits);

	std::cout << "Here your digits, they are saved in file.\n";

	for (int i = 0; i < amount_digits; i++) {
		numbers[i] = rand() % power;
		std::cout << numbers[i] << "\n";
	}

	saveToFile(numbers, amount_digits);
	delete[] numbers;
}

int main() {
	srand((unsigned int)time(nullptr));
	printHeader();
	generateRandomNumbers();

	return 0;
}
