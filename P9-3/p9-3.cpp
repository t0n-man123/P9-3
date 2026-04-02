#include <iostream>
#include <random>
using namespace std;
// Atehrton bunner; runnin and runnin and runnin
void displayRun(int values[], int size);
bool hasRun(int values[], int size);
int main() {
	// setting up random generation
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution dist(1,6);
	// variables
	const int LENGTH = 20;
	int values[LENGTH];
	//while (true) {
		for (int i = 0; i < LENGTH; i++) { // roll the dice
			values[i] = dist(gen);
		}
		displayRun(values, LENGTH);
	//}
}
void displayRun(int values[], int size) { // the output
	for (int j = 0; j < size - 1; j++) {
		if (values[j] == values[j + 1] && values[j] != values[j - 1]) { // start of run
			cout << "(";
		}
		cout << values[j];
		if (values[j] == values[j - 1] && values[j] != values[j + 1]) { // end of run
			cout << ")";
		}
		cout << " ";
	}
}
bool hasRun(int values[], int size) {
	for (int j = 0; j < size - 1; j++) {
		if ((values[j] == values[j + 1] && values[j] != values[j - 1])) {
			return true;
		}
	}
	return false;
}