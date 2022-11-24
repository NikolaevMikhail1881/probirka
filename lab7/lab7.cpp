//lab 5.1

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Matrix {

public:
	int Row; // строки
	int Column; // столбцы
	double* Array; // динамический массив

public:
	void sum(const Matrix* mat2);
	void mult(const Matrix* mat2);
	double trace();
	double det();
	void mult_by_num(double num);
	void input();
	void print();
	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
};

void Matrix::input() {
	cout << "Введите кол - во строк : ";
	cin >> Row;
	cout << "Введите кол - во столбцов : ";
	cin >> Column;
	cout << "Заполните массив : \n"; 
	this->Array = new double[Row * Column];
	for (int i = 0; i < Row * Column; i++) {
		cin >> Array[i];
	}
}

void Matrix::print() {
	cout << "Матрица равна :" << endl; 
	for (int i = 0; i < Row * Column; i++ ) {
		cout << Array[i] << " "; 
	}
}

double Matrix::trace() {
	double sum = 0;
	if (Row == Column) {
		int counter = 0;
		for (int i = 0; i < Row * Column; i++ ) {
			if (i == counter) {
				sum += Array[i];
				counter += Column + 1;
			} 
		}
		return sum; 
	}
	else {
		cout << "Матрица не является квадратной ! \n";
		return sum;
	}
}

int Matrix::get_rows() {
	return Row; 
}
int Matrix::get_columns() {
	return Column;
}
double Matrix::get_elem(int i, int j) {
	return 
}
int main() {
	setlocale(LC_ALL, "RU");
	Matrix test;
	test.input();
	double summary = test.trace();
	cout << "След матрицы : " << summary; 
	return 0;
}


