#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <string>
//#include <string.h>

//using namespace std;

/*
To do:
1) sorting the table,
2) delete number, which have too small lenght of number of digits,
3) delete std:: -> using namespace std;
*/

void digits();
void folder(int *tab, int n);

int main(){
	digits();
	return 0;	
}

void digits(){
	int x=0, result, number_digits;
	int *number = new int[x];
	srand((unsigned int)time(NULL));
	
	std::cout << "============================================" << std::endl;
	std::cout << "= SIMPLE PROGRAM TO GENERATE RANDOM DIGITS =" << std::endl;
	std::cout << "============================================" << std::endl;

	std::cout << "Enter number of elements: ";
	std::cin >> x;
	
	//first condition - too many elements :/
	if (x > 1000000){
		std::cout << "ERROR - too many elements!\nThe program is shutting down..." << std::endl;
		return;
	}

	number = new int[x];
	int* wsk = number;
	
	std::cout << "Enter the max lenght of the number (number of digits): ";
	std::cin >> number_digits;

	std::cout << "Here your numbers:" << std::endl;

	result = pow(10, number_digits);

	for(int i=0; i<x; i++){
		number[i]=rand()%result;
		std::cout << number[i] << std::endl;
	}
	
	folder(wsk, x);
	delete[] number;
}

void folder(int *tab, int n){
	std::ofstream file("return.txt");

	if(file.is_open()){
		for(int i=0; i<n; i++){
			file << tab[i] << std::endl;
		}
		file.seekp(0, std::ios::end);
		long long size = file.tellp();		
		std::cout << "The file is saved as " << "." << std::endl;
		std::cout << size << " byte(s)" << std::endl;
	}

	else{
		std::cout << "ERROR - I cannot open the file!" << std::endl;
	}
	
}
