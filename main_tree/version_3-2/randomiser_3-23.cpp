#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

void printHeader() {
	std::cout
		<< "=====================================================\n"
		<< "= CRAZY ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =\n"
		<< "=====================================================\n";
}

int getInt(const std::string& prompt, int min, int max) {
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

std::string getName() {
	std::string appellation;
	std::cout << "Enter a full name of your new file: ";
	std::cin >> appellation;
	return appellation;
}

void saveToFile(int* data, int size, const std::string& file_name) {
	std::ofstream file(file_name);

	if (file.is_open()) {
		for (int i = 0; i < size; i++)
			file << i + 1 << "\t" << data[i] << "\n";
		file.seekp(0, std::ios::end);
		long long sizeFile = file.tellp();
		std::cout << "The file is saved as " << file_name << ".\n";
		std::cout << sizeFile << " byte(s)\n";
	}

	else {
		std::cout << "ERROR - cannot open the file!\n";
		return;
	}

	file.close();
}

void generateRandomNumbers() {
	const int max_amount = 100000;
	const int max_lenght = 10;

	int amount = getInt("Enter amount of random digits: ", 1, max_amount);
	int lenght = getInt("Enter max lenght of number: ", 1, max_lenght);

	int* numbers = new int[amount];
	int power = 1;

	for (int i = 0; i < lenght; i++) {
		power *= 10;
	}

	for (int i = 0; i < amount; i++) {
		numbers[i] = rand() % power;
		if (amount <= 100)
			std::cout << i + 1 << "\t" << numbers[i] << "\n";
	}
	std::string name = getName();
	saveToFile(numbers, amount, name);
	delete[] numbers;
}

int main() {
	srand((unsigned int)time(nullptr));
	printHeader();
	generateRandomNumbers();

	return 0;
}
