// lab 4.2
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void task_1(char* c, int size) {
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (c[i] == '.') {
			flag = true;
		}
		if (flag) {
			cout << c[i];
		}
	}
	cout << endl;
}
void task_2(char* c, int size) {
	char* a = new char[size];
	bool flag = false;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (c[i] == '\\') {
			flag = true;
			counter = 0;
		}
		if (flag) {
			a[counter] = c[i];
			counter++;
		}
		if (c[i] == '.') {
			break;
		}
	}
	for (int i = 1; i < counter - 1; i++) {
		cout << (char)a[i];
	}
	cout << endl;
}

void task_3(char* c) {
	cout << c[0] << c[1]; 
	cout << endl; 
}

void task_4(char* c, int size) {
	char* a = new char[size];
	int schz = 0;
	for (int i = size; i >= 0; i--) {
		if (c[i] == '\\') {
			a[schz] = c[i];
			schz++;
		}
		else if (schz > 0) {
			a[schz] = c[i];
			schz++;

		}
	}
	for (int i = schz - 1 ; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;
}

void task_5(char*c, int size) {
	cout << "Введите новое название файла :\n";
	string n;
	cin >> n;
	char* b = new char[n.length()];
	char* a = new char[size];
	int schz = 0;
	for (int i = size; i >= 0; i--) {
		if (c[i] == '\\') {
			a[schz] = c[i];
			schz++;
		}
		else if (schz > 0) {
			a[schz] = c[i];
			schz++;
		}
	}
	for (int i = schz - 1; i >= 0; i--) {
		cout << a[i];
	}
}

int main() {
	setlocale(LC_ALL, "RU");         // Подключаем функцию позволяющия выводить русскоязычные слова 
	int n;
	bool flag = true;
	string filepath;
	cout << "Введите полный путь к файлу : ";
	cin >> filepath;
	char *c = new char[filepath.length()];
	for (int i = 0; i < filepath.length(); i++) {
		c[i] = filepath[i];
	}

	while (flag) {
		cout << "Введите 0 для выхода* \n";
		cout << "Введите номер задания : ";
		cin >> n;
		switch (n) {
		case 1: task_1(c, filepath.length());
			break;
		case 2: task_2(c, filepath.length());
			break;
		case 3: task_3(c);
			break;
		case 4: task_4(c, filepath.length());
		case 5: task_5(c, filepath.length());
			break;
		case 0:
			flag = false;
			break;
		}
	}
}
