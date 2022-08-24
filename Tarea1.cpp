#include <iostream>
#include <chrono>
#include <random>

#define MAX 500
using namespace std;

int main() {
	int A[MAX][MAX], x[MAX], y[MAX];

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			A[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < MAX; i++) {
		x[i] = rand() % 100;
		y[i] = 0;
	}


	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			y[i] += A[i][j] * x[j];
		}
	}

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
		elapsed).count();
	cout << "El tiempo en microsegundos del primer loop es: " << microseconds << endl;

	start = std::chrono::high_resolution_clock::now();
	for (int j = 0; j < MAX; j++) {
		for (int i = 0; i < MAX; i++) {
			y[i] += A[i][j]* x[j];
		}
	}

	elapsed = std::chrono::high_resolution_clock::now() - start;
	microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
		elapsed).count();
	cout << "El tiempo en microsegundos del segundo loop es: " << microseconds << endl;
}