#include <iostream> 
#include <cmath> 
#include <cstdlib> 
#include <fstream>
#include <ctime>

using namespace std;

void console(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// Вивід матриці в консоль
void PrintMatrix(int** matrix, int m, int n)
{

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] <<  "\t";
		}
		cout << endl;
	}
}

// Функція для знаходження максимального елемента в матриці
int FindMax(int** matrix, int n, int m)
{
	int maximum = matrix[0][0];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] > maximum) {
				maximum = matrix[i][j];
			}
		}
	}

	return maximum;
}

//Функція для ізбульшення елементів матриці
void ZbilshitiMatrix(int** matrix, int m, int n, int zxc)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] += zxc;
		}
	}
}

// Функція для заміни стовпців
void SwapCols(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++) {
		swap(matrix[i][0], matrix[i][n - 1]);
	}
}

// Функція для звільнення пам'яті, виділеної для матриці
void RemoveMem(int** matrix, int m)
{
	for (int i = 0; i < m; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// Функція для заміни від'ємних елементів матриці B мінімальним елементом матриці A
void Replace(int** MatrixA, int** MatrixB, int m, int n, int minA)
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (MatrixB[i][j] < 0) {
				MatrixB[i][j] = minA;
			}
		}
	}
}

// Функція для створення і генерації чисел для матриці
int** CreateMatrix(int m, int n)
{
	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}

	// Заповнення матриці випадковими числами
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = rand() % 20 - 10; // Генеруємо випадкові числа від -10 до 9
		}
	}

	return matrix;
}

// Записуємо матрицю в текстовий файл
void file(const string& file_name, int n)
{
	ofstream ofs;
	ofs.open(file_name);
	if (!ofs) {
		cout << "file is not open." << endl;
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		ofs << rand() % 21 << " ";
	}
	ofs.close();
}

void file_auto(const string& file_name, int m, int n, int** matrix)
{

	ifstream ifs;
	ifs.open(file_name);
	if (!ifs) {
		cout << "file is not open." << endl;
		exit(-1);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ifs >> matrix[i][j];
		}
	}
	ifs.close();
}

int main(int minElement, int minRow, int minColumn)
{

	setlocale(LC_ALL, "ru");

	cout << "Виконав студент 1 курсу Сторожук Назар Валерійович Группи ІР-12 3 підгрупи" << endl;

	cout << "Варіант 13 згідно списків" << endl << "Рівенб складності: A" << endl << endl;

	int choice = 0;

	srand(time(nullptr)); // Инициализация генератора случайных чисел

	int** matrix = nullptr;
	int n = 0;
	int m = 0;

	cout << "m(рядки) :";
	cin >> m;
	cout << "n(стовпці) :";
	cin >> n;
	if (n < 6 || m < 6) {
		cout << "n and m should be > 6 " << endl;
		return 1;
	}
	else if (n == m) {
		cout << "should be different" << endl;
		return 1;
	}

	int** MatrixA = CreateMatrix(m, n);
	int** MatrixB = CreateMatrix(m, n);

	cout << "1: Fill from console;" << endl;
	cout << "2: Fill from file;" << endl;
	cin >> choice;

	if (choice == 1) {
		cout << "Matrix A: " << endl;
		PrintMatrix(MatrixA, m, n);
		cout << endl;

		cout << "Matrix B: " << endl;
		PrintMatrix(MatrixB, m, n);
		cout << endl;

		int maxB = FindMax(MatrixB, m, n);

		ZbilshitiMatrix(MatrixA, m, n, maxB);

		SwapCols(MatrixA, m, n);

		cout << "Max element matrix B: " << maxB << endl << endl;
		cout << "Modified matrix A: " << endl;
		PrintMatrix(MatrixA, m, n);

		RemoveMem(MatrixA, m);
		RemoveMem(MatrixB, m);
	}
	else if (choice == 2) {
		file("a.txt", n * m);
		file("b.txt", n * m);
		file_auto("a.txt", m, n, MatrixA);
		file_auto("b.txt", m, n, MatrixB);
	}
	else {
		cout << "Invalid choice.";
		return 1;
	}

	
	return 0;

}



/*
// Введення з клавіатури
int** entermatrix(int& m, int& n)
{

	int** matrix = new int* [m];

	for (int i = 0; i < m; i++) {

		matrix[i] = new int[n];

	}

	cout << "Введіть елементи матриці: " << endl;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			if (m < 3 || n < 3) {
				cout << "Кількість стовпців має бути > 3!" << endl;
				exit(1);
			}
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	return matrix;
}
*/