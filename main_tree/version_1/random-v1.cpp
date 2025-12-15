#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void digit(int x);
void plik(int x, int tab[]);

int main(){
	int x=0;
	cout << "Enter how many elements do you need? [max 100] ";
	cin >> x;
	digit(x);
	return 0;
}

void digit(int x){
	int num[100];
	srand((unsigned int)time(NULL));

	if (x > 100){
		cout << "To many elements";
		return;
	}
	
	for(int i=0; i<x; i++){
		num[i]=rand();
	}
	plik(x, num);	
}

void plik(int x, int tab[]){
	ofstream plik("return.txt");
	if(plik.is_open()){
		for(int i=0; i<x; i++){
			plik << tab[i] << endl;
		}
		cout << "\nThe file is saved.\n";
	}

	else{
	cout << "\nError, cannot open file!\n";
	}
}
