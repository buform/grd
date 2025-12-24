#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

void make_digits();
void make_file(int *board, int size);

// main function - only starts function make_digits()
int main(){
	cout << "=====================================================" << endl;
	cout << "= SIMPLE ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =" << endl;
	cout << "=====================================================" << endl;

	make_digits();

	return 0;
}

// this function generate random digits and sents them to function make_file()
void make_digits(){
	int amount_digits, lenght_digits, tech_value;
	const int max_amount = 1000000; //6 zero
	const int max_lenght = 10;

	srand((unsigned int)time(NULL));

	cout << "Enter amount of random digits - "; 
	cin >> amount_digits;

	// first condition - too many elements
	if (amount_digits > max_amount) {
		cout << "Too many elements to generate - for some machines it is too much!\nThe algorithm will shut down..." << endl;
		return;

	}

	int *file_board = new int[amount_digits];

	cout << "Enter the max lenght of the number (number of digits) - ";
	cin >> lenght_digits;

	if (lenght_digits > max_lenght) {
		cout << "Too long digits!\nThe algorithm will shut down..." << endl;
		return;
	}

	tech_value = pow(10, lenght_digits);

	cout << "Here your digits, they are saved in file." << endl;

	for (int i = 0; i < amount_digits; i++) {
		file_board[i] = rand() % tech_value;
		cout << file_board[i] << endl; 
	}
	
	make_file(file_board, amount_digits);
	delete[] file_board;
}

// this function saves random digits form function make_digits() to file (.txt)
void make_file(int *board, int x){
	string file_name = "return.txt";
	ofstream file(file_name);

	if (file.is_open()) {
		for (int i = 0; i < x; i++)
			file << board[i] << endl;
		file.seekp(0, ios::end);
		long long size = file.tellp();
		cout << "The file is saved as " << file_name << "." << endl;
		cout << size << " byte(s)" << endl;
	}

	else {
		cout << "ERROR - cannot open the file!" << endl;
	}

	file.close();
}
