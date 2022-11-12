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

int main() {
	setlocale(LC_ALL, "RU");         // Подключаем функцию позволяющия выводить русскоязычные слова 
	int n;
	bool flag = true;
	string filepath;
	cout << "Введите полный путь к файлу : ";
	cin >> filepath;
	char *c = new char[filepath.length()+1];
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
		case 0:
			flag = false;
			break;
		}
	}
}
