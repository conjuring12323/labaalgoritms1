﻿#include <iostream> 
#include<cmath>
#include <cstdlib> 
#include <fstream>
#include <ctime>
#include <chrono>
#include<Windows.h>

using namespace std;
using namespace std::chrono;


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


// Функція для звільнення пам'яті, виділеної для матриці
void RemoveMem(int** matrix, int m)
{
	for (int i = 0; i < m; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

/*
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
*/
// Функція для створення матриці
int** CreateEmptyMatrix(int m, int n)
{
	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}
	return matrix;
}
void FillMatrixWithRandomNumbers(int** matrix, int m, int n)
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = rand() % 20 - 10; // Генеруємо випадкові числа від minVal до maxVal
		}
	}
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

void WriteMatrixToFile(ofstream& ofs, int** matrix, int m, int n, const string& matrixName)
{
	ofs << matrixName << ":" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			ofs << matrix[i][j] << "\t";
		}
		ofs << endl;
	}
	ofs << endl;
}




//Функція для збільшення елементів матриці
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
//void time1(int m, int count, int k, int n1)
//{
//	double start = 0, end = 0, average = 0;
//
//	string name = "results1.txt";
//	ofstream results1;
//	results1.open(name);
//
//	if (!results1.is_open())
//		cout << "Помилка відкриття файлу!" << endl;
//	else
//	{
//		for (int i = m; i < n1; i += k)
//		{
//			average = 0;
//
//			for (int j = 0; j < count; j++)
//			{
//
//
//				int m = i, n = i + 1;
//
//				int** MatrixA = CreateEmptyMatrix(m, n);
//				FillMatrixWithRandomNumbers(MatrixA, m, n);
//				int** MatrixB = CreateEmptyMatrix(m, n);
//				FillMatrixWithRandomNumbers(MatrixB, m, n);
//
//				high_resolution_clock::time_point start = high_resolution_clock::now();
//
//				int maxB = FindMax(MatrixB, m, n);
//				ZbilshitiMatrix(MatrixA, m, n, maxB);
//
//				high_resolution_clock::time_point end = high_resolution_clock::now();
//
//				RemoveMem(MatrixA, m);
//				RemoveMem(MatrixB, m);
//
//				duration<double> time_span = duration_cast<duration<double>>(end - start);
//
//				average += time_span.count();
//
//				cout << "Час виконання програми на кількості данних першого алгоритму: " << i << ": " << time_span.count() << endl;
//				results1 << "Час виконання програми на кількості данних першого алгоритму: " << i << ": " << time_span.count() << endl;
//			}
//
//			average = average / count;
//
//			cout << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
//			results1 << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
//		}
//	}
//
//	results1.close();
//}

//void time2(int m, int count, int k, int n1)
//{
//	double start = 0, end = 0, average = 0;
//
//	string name = "results2.txt";
//	ofstream results2;
//	results2.open(name);
//
//	if (!results2.is_open())
//		cout << "Помилка відкриття файлу!" << endl;
//	else
//	{
//		for (int i = m; i < n1; i += k)
//		{
//			average = 0;
//
//			for (int j = 0; j < count; j++)
//			{
//
//
//				int m = i, n = i + 1;
//
//				int** MatrixA = CreateEmptyMatrix(m, n);
//				FillMatrixWithRandomNumbers(MatrixA, m, n);
//				int** MatrixB = CreateEmptyMatrix(m, n);
//				FillMatrixWithRandomNumbers(MatrixB, m, n);
//
//				high_resolution_clock::time_point start = high_resolution_clock::now();
//
//				SwapCols(MatrixA, m, n);
//
//				high_resolution_clock::time_point end = high_resolution_clock::now();
//
//				RemoveMem(MatrixA, m);
//				RemoveMem(MatrixB, m);
//
//				duration<double> time_span = duration_cast<duration<double>>(end - start);
//
//				average += time_span.count();
//
//				cout << "Час виконання програми на кількості данних Другого алгоритму: " << i << ": " << time_span.count() << endl;
//				results2 << "Час виконання програми на кількості данних Другого алгоритму: " << i << ": " << time_span.count() << endl;
//			}
//
//			average = average / count;
//
//			cout << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
//			results2 << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
//		}
//	}
//
//	results2.close();
//}


void time1(int m, int count, int k, int n1)
{
	double start = 0, end = 0, average = 0;

	string name = "results.txt";
	ofstream results;
	results.open(name);

	if (!results.is_open())
		cout << "Помилка відкриття файлу!" << endl;
	else
	{
		for (int i = m; i < n1; i += k)
		{
			average = 0;

			for (int j = 0; j < count; j++)
			{

				int m = i, n = i + 1;

				int** MatrixA = CreateEmptyMatrix(m, n);
				FillMatrixWithRandomNumbers(MatrixA, m, n);
				int** MatrixB = CreateEmptyMatrix(m, n);
				FillMatrixWithRandomNumbers(MatrixB, m, n);

				start = clock();


				int maxB = FindMax(MatrixB, m, n);
				ZbilshitiMatrix(MatrixA, m, n, maxB);
				end = (clock() - start) / 1000;

				RemoveMem(MatrixA, m);
				RemoveMem(MatrixB, m);

				

				average += end;

				cout << "Час виконання програми на кількості данних першого алгоритму: " << i << ": " << end << endl;
				results << "Час виконання програми на кількості данних першого алгоритму: " << i << ": " << end << endl;
			}

			average = average / count;

			cout << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
			results << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
		}
	}

	results.close();
}


void time2(int m, int count, int k, int n1)
{
	double start = 0, end = 0, average = 0;

	string name = "results_1.txt";
	ofstream results_1;
	results_1.open(name);

	if (!results_1.is_open())
		cout << "Помилка відкриття файлу!" << endl;
	else
	{
		for (int i = m; i < n1; i += k)
		{
			average = 0;

			for (int j = 0; j < count; j++)
			{
				// поставить точку отчета между функцией свапколлс

				int m = i, n = i + 1;

				int** MatrixA = CreateEmptyMatrix(m, n);
				FillMatrixWithRandomNumbers(MatrixA, m, n);
				int** MatrixB = CreateEmptyMatrix(m, n);
				FillMatrixWithRandomNumbers(MatrixB, m, n);

				start = clock();

				

				SwapCols(MatrixA, m, n);


				end = (clock() - start) / 1000;

				RemoveMem(MatrixA, m);
				RemoveMem(MatrixB, m);

				

				average += end;

				cout << "Час виконання програми на кількості данних Другого алгоритму: " << i << ": " << end << endl;
				results_1 << "Час виконання програми на кількості данних Другого алгоритму: " << i << ": " << end << endl;
			}

			average = average / count;

			cout << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
			results_1 << endl << "Середнє арифметичне(" << i << "): " << average << endl << endl;
		}
	}

	results_1.close();
}

int main()
{
	int n1 = 0;
	int k = 0;
	int count = 0;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Виконав студент 1 курсу Сторожук Назар Валерійович Группи ІР-12 3 підгрупи" << endl;
	cout << "Варіант 13 згідно списків" << endl << "Рівенб складності: A" << endl << endl;

	int choice = 0;

	srand(unsigned int (time(nullptr))); // Инициализация генератора випадкових чисел

	int** matrix = nullptr;
	int n = 0;
	int m = 0;

	cout << "m(рядки) > 6 m != n:";
	cin >> m;
	cout << "n(стовпці) > 6 n != m:";
	cin >> n;
	if (n < 6 || m < 6) {
		cout << "n and m should be > 6 " << endl;
		return 1;
	}
	else if (n == m) {
		cout << "should be different" << endl;
		return 1;
	}

	int** MatrixA = CreateEmptyMatrix(m, n);
	FillMatrixWithRandomNumbers(MatrixA, m, n);
	int** MatrixB = CreateEmptyMatrix(m, n);
	FillMatrixWithRandomNumbers(MatrixB, m, n);

	cout << "1:записати матрицю в консоль;" << endl;
	cout << "2:записати матрицю в файл;" << endl;
	cin >> choice;

	if (choice == 1) {

		bool vibir = 0;
		cout << "You wanna see the matrix? (1/0)" << endl;
		cin >> vibir;
		if (vibir) {
			cout << "Matrix A: " << endl;
			PrintMatrix(MatrixA, m, n);
			cout << endl;

			cout << "Matrix B: " << endl;
			PrintMatrix(MatrixB, m, n);
			cout << endl;
		}

		int maxB = FindMax(MatrixB, m, n);

		
		
		cout << "Замір часу для першого алгоритму: " << endl;
		cout << "Max element matrix B: " << maxB << endl << endl;
		cout << "Amount of itarationns: ";
		cin >> count;
		cout << "Krok: ";
		cin >> k;
		cout << "Put max matrix size: ";
		cin >> n1;
		time1(m, count, k, n1);

		
		cout << "Замір часу для другого алгоритму: " << endl;
		cout << "Amount of itarationns: ";
		cin >> count;
		cout << "Krok: ";
		cin >> k;
		cout << "Put max matrix size: ";
		cin >> n1;
		time2(m, count, k, n1);
		
		cout << "You wanna see the modified matrix? (1/0)" << endl;
		cin >> vibir;
		cout << "Modified matrix A: " << endl;
		if (vibir) {
			PrintMatrix(MatrixA, m, n);
		}
		
	}
	else if (choice == 2) {
		bool vibir = 0;
		// n * m задає розмір файла при створенні
		file("a.txt", n * m);
		file("b.txt", n * m);
		file_auto("a.txt", m, n, MatrixA);
		file_auto("b.txt", m, n, MatrixB);

		cout << "You wanna see the  matrix? (1/0)" << endl;
		cin >> vibir;
		
		if (vibir) {
			cout << "Matrix A: " << endl;
			PrintMatrix(MatrixA, m, n);
			cout << endl;

			cout << "Matrix B: " << endl;
			PrintMatrix(MatrixB, m, n);
			cout << endl;
		}
	}
	else {
		cout << "Invalid choice.";
		return 1;
	}

	cout << "Виберіть дію:" << endl;
	cout << "1:Закрити програму" << endl;
	cout << "2:Записати склад консолі в файл" << endl;
	cin >> choice;

	if (choice == 1) {
		RemoveMem(MatrixA, m);
		RemoveMem(MatrixB, m);
		return 0;
	}
	else if (choice == 2) {
		bool vibir = 0;
		// Запис складу у файл
		file("a.txt", n * m);
		file("b.txt", n * m);

		
		//file_auto("a.txt", m, n, MatrixA);
		//file_auto("b.txt", m, n, MatrixB);
		

		cout << "You wanna see the  matrix? (1/0)" << endl;
		cin >> vibir;

		if (vibir) {
			cout << "Matrix A: " << endl;
			PrintMatrix(MatrixA, m, n);
			cout << endl;

			cout << "Matrix B: " << endl;
			PrintMatrix(MatrixB, m, n);
			cout << endl;
		}
		
		// Запусуємо склад консолі у файл
		ofstream ofs("output.txt");
		WriteMatrixToFile(ofs, MatrixA, m, n, "Matrix A");
		WriteMatrixToFile(ofs, MatrixB, m, n, "Matrix B");
		ofs.close();
		cout << "Склад консолі успішно записаний у файл'" << endl;
	}
	else {
		cout << "Invalid choice. Exiting program." << endl;
	}

	

	RemoveMem(MatrixA, m);
	RemoveMem(MatrixB, m);

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