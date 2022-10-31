#include <iostream>

using std::cin;
using std::cout;
using std::endl; 
using std::string;


bool task_1(char arr[], int k) {
	char vsp[255]; 
	int sch = 0;
	for (int i = k - 1; i >= 0; i--) {
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

void task_2(char arr[],int k) {
	cout << "Введите подстроку : ";
	string str; 
	cin >> str;
	int sch = 0;
	int sch2 = 0;
	for (int i = 0; i < k; i++) {
		if (arr[i] == str[sch]) {
			sch2++;
			sch++;
		}
		else {
			sch2 = 0;
			sch = 0;
		}

	}
}








int main() {
	setlocale(LC_ALL, "RU");
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
		case 2: task_2();
			break;
		case 0:
			flag = false;
			break;
		}
	}
}