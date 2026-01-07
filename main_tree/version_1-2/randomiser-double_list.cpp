#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>
#include <climits>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

void deleteList(Node* &head, Node* &tail) {
	Node* tmp = head;
	Node* nextNode;

	while(tmp != nullptr) {
		nextNode = tmp->next;
		delete tmp;
		tmp = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}

void addNode(Node* &head, Node* &tail, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = nullptr;

	if (head != nullptr) head->prev = newNode;
	else tail = newNode;

	head = newNode;
}

void printHeader() {
	std::cout
		<< "=====================================================\n"
		<< "= CRAZY ALGORITHM TO GENERATE RANDOM DIGITS IN C++ =\n"
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

std::string getName() {
	std::string appellation;
	std::cout << "Enter a full name of your new file: ";
	std::cin >> appellation;
	return appellation;
}

void saveToFile(Node* head, Node* tail, int size, const std::string& file_name) {
	std::ofstream file(file_name);
	Node* tmp = head;

	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << i + 1 << "\t" << tmp->data << "\n";
			tmp = tmp->next;
		}
		file.seekp(0, std::ios::end);
		long long size = file.tellp();
		std::cout << "The file is saved as " << file_name << ".\n";
		std::cout << size << " byte(s)\n";
	}

	else {
		std::cout << "ERROR - cannot open the file!\n";
		return;
	}

	file.close();
}

void generateRandomNumbers(Node* &head, Node* &tail) {
	const int max_amount = 1000000;
	const int max_lenght = 9;

	int amount = getInt("Enter amount of random digits: ", 1, max_amount);
	int lenght = getInt("Enter max lenght of number: ", 1, max_lenght);

	int power = (int)pow(10, lenght);

	for (int i = 0; i < amount; i++) {
		int value = rand() % power;
		addNode(head, tail, value);
	}
	std::string name = getName();
	saveToFile(head, tail, amount, name);
}

int main() {
	Node* head = nullptr;
	Node* tail = nullptr;

	srand((unsigned int)time(nullptr));

	printHeader();
	generateRandomNumbers(head, tail);
	deleteList(head, tail);

	return 0;
}
