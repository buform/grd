#include <iostream>
#include <fstream>
#include <string>

std::string getInfo() {
	std::string filename;

	std::cout << "Enter a full name of file: ";
	std::cin >> filename;

	return filename;
}

void showDigits(const std::string& route) {
	std::cout << route << "\n";
}

void readFile(const std::string& name) {
	std::ifstream file(name);
	std::string line;

	if (!file.is_open()) {
		std::cout << "ERROR - cannot open the file!\n";
		return;
	}

	while (std::getline(file, line))
		showDigits(line);

	file.close();
}

int main() {
	std::string name = getInfo();
	readFile(name);
	return 0;
}
