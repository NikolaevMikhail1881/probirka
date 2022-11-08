#include <iostream>

using std::cin;
using std::cout;
using std::endl; 
using std::string;     // string - тип данных, (массив символов)


bool task_1(char arr[], int k) {           // bool - потому что функция возвращает логическое значение (true/false)
	char vsp[255]; 
	int sch = 0;
	for (int i = k - 1; i >= 0; i--) {     // k - переменная которая хранит индекс положении точки.  i = k - 1 (чтобы мы начинали сравнение с символа  а не с точки)
		vsp[sch] = arr[i];
		sch++;
	}
	/*cout << "VSP : ";
	for (int i = 0; i < k; i++) {
		cout << vsp[i]; 
	}*/
	for (int i = 0; i < k; i++) {
		if (vsp[i] != arr[i]) {
			return false;
		}
	}
	return true; 
}

void task_2(char arr[],int k) {    // Передаем массив и положение точки
	cout << "Введите подстроку : ";
	string str; 
	cin >> str;
	int sch = 0;
	int sch2 = 0;
	int sch3 = 0;
	int mass[255];
	int perem = 0; 
	for (int i = 0; i < k; i++) {
		if (arr[i] == str[sch]) {
			sch2++;
			sch++;
			if(sch == 1) {
				mass[sch3] = i;
			}
			if(sch2 == str.size()) {
				perem++;
				sch3++;
				sch = 0;              // Обнуляем чтобы не выйти за пределы строки. 
				sch2 = 0;           
			}
		}
		else {
			sch2 = 0;
			sch = 0;
		}

	}
	cout << "Введёная подстрока найдена на следующих местах : " << endl;
	cout << "[";
	for (int i = 0; i < perem; i++) {
		cout << mass[i];
		if (i != perem - 1) {    // Если проверяем елемент и он является последним то запятая не выводится.
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void task_3(char arr[], int k) {
	cout << "Введите ключ для шифра : ";
	int kl;
	cin >> kl; 

}








int main() {
	setlocale(LC_ALL, "RU");         // Подключаем функцию позволяющия выводить русскоязычные слова 
	int n;
	bool flag = true;

	char arr[255];
	int i = 0;
	cout << "Введите символьный массив : ";
	cin >> arr[i];
	while (arr[i] != '.') {
		i++;
		cin >> arr[i];
	}

	while (flag) {
		cout << "Введите 0 для выхода* \n";
		cout << "Введите номер задания : ";
		cin >> n;


		switch (n) {
		case 1: 
			if (task_1(arr, i)) {
				cout << "Данная строка является палиндромом \n";
			}
			else {
				cout << "Данная строка не является палиндромом \n";
			}
			break;
		case 2: task_2(arr, i);
			break;
		case 3: task_3(arr, i);
			break;
		case 0:
			flag = false;
			break;
		}
	}
}