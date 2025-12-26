#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

void generateRandomNumbers();
void saveToFile(int *board, int size);

// main function - only starts function make_digits()
int main(){
	std::cout << "=====================================================\n";
	std::cout << "= SIMPLE ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =\n";
	std::cout << "=====================================================\n";

	srand((unsigned int)time(nullptr));

	generateRandomNumbers();

	return 0;
}

// this function generate random digits and sents them to function saveToFile()
void generateRandomNumbers(){
	int amount_digits, lenght_digits, value;
	const int max_amount = 1000000; //6 zero
	const int max_lenght = 10;

	std::cout << "Enter amount of random digits - "; 

	if (!(std::cin >> amount_digits)) {
    	std::cout << "Invalid input!" << std::endl;
    	return;
	}
	if (amount_digits > max_amount) {
    	std::cout << "Too many elements to generate!" << std::endl;
    	return;
	}

	std::cout << "Enter the max length of the number (number of digits) - ";
	if (!(std::cin >> lenght_digits)) {
    	std::cout << "Invalid input!" << std::endl;
    	return;
	}
	if (lenght_digits > max_lenght) {
    	std::cout << "Too long digits!" << std::endl;
	    return;
	}

	int *numbers = new int[amount_digits];

	value = pow(10, lenght_digits);

	std::cout << "Here your digits, they are saved in file.\n";

	for (int i = 0; i < amount_digits; i++) {
		numbers[i] = rand() % value;
		std::cout << numbers[i] << "\n";
	}
	
	saveToFile(numbers, amount_digits);
	delete[] numbers;
}

// this function saves random digits form function generateRandomNumbers() to file (.txt)
void saveToFile(int *board, int size){
	std::string file_name = "return.txt";
	std::ofstream file(file_name);

	if (file.is_open()) {
		for (int i = 0; i < size; i++)
			file << board[i] << "\n";
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
