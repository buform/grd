#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void liczba(int x);
void plik(int x, int tab[]);

int main(){
	int x=0;
	cout << "Podaj ilosc [maksymalnie 100]: ";
	cin >> x;
	liczba(x);
	return 0;
}

void liczba(int x){
	int numer[100];
	srand((unsigned int)time(NULL));

	if (x > 100){
		cout << "Za duzo elementow!";
		return;
	}
	
	for(int i=0; i<x; i++){
		numer[i]=rand();
	}
	plik(x, numer);	
}

void plik(int x, int tab[]){
	ofstream plik("wynik.txt");
	if(plik.is_open()){
		for(int i=0; i<x; i++){
			plik << tab[i] << endl;
		}
		cout << "\nLiczby zapisano do pliku\n";
	}

	else{
	cout << "\nBlad: nie mozna otworzyc pliku do zapisu\n";
	}
}
