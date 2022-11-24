#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;         
using std::ofstream;


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
	for (int i = schz - 1; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;
}

void task_5(char* c, int size) {
	cout << "Введите новое название файла :\n";
	string n;
	cin >> n;
	char* b = new char[n.length()];
	for (int i = 0; i < n.length(); i++) {
		b[i] = n[i];
	}
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
	int zx = 0;
	char* m = new char[n.length() + schz + 4];
	for (int i = schz - 1; i >= 0; i--) {
		m[zx] = a[i];
		zx++;
	}

	zx = 0;
	for (int i = schz; i < schz + n.length(); i++) {
		m[i] = b[zx];
		zx++;
	}

	for (int i = 0; i < schz + n.length(); i++) {
		cout << m[i];
	}

	for (int i = size - 4; i < size; i++) {
		cout << c[i];
	}
	cout << endl;
}

bool task_6(const string file_path_full) {
	const string file_path_full_copy = "D:\\Application Files\\test_copy.txt";
	ifstream fin(file_path_full);
	ofstream fout(file_path_full_copy);
	char buff[50];
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof()) {
			fin.getline(buff, 50);
			fout << buff << endl;
		}
		fin.close();
		fout.close();
		return true;
	}
	else {
		return false;
	}
}


int main() {
	setlocale(LC_ALL, "RU");         // Подключаем функцию позволяющия выводить русскоязычные слова 
	const string file_path_full = "D:\\Application Files\\test.txt";
	int n;
	bool flag = true, task = true;
	string filepath;
	cout << "Введите полный путь к файлу : ";
	cin >> filepath;
	char* c = new char[filepath.length()];
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
			break;
		case 5: task_5(c, filepath.length());
			break;
		case 6:
			task = task_6(file_path_full);
			if (!task) {
				cout << "Ошибка при открытии файла!" << endl;
			}
			else {
				cout << "Файл скопирован." << endl;
			}
			break;
		case 0:
			flag = false;
			break;
		}
	}
}