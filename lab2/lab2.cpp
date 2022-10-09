#include <iostream> 
#include <string> 

using std::cin; 
using std::cout;


void task_1() {
	int m;
	cout << "Введите число: ";
	cin >> m;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= i; j++) {
			cout << j;

		}
		cout << "\n";
	}
}
unsigned long long fact(int b) {
	if (b == 0) return 1;
	unsigned long long k = 1;
	for (int i = 1; i <= b; i++) {
		k = k * i;
	} return k;
}

void task_2() {
	int n;

	cout << "Введите число n: ";
	cin >> n;
	cout << "Ваши биномиальные коэфиценты\n";
	for (int i = 0; i <= n; i++) {
		cout << fact(n) / (fact(i) * fact(n - i)) << " ";
	}
}


void task_3() {
	int sum = 0, col, x = 1;
	for (int i = 0; x != 0; i++) {
		cout << "Введите " << i << "-е число : ";
		cin >> x;
		sum = sum + x;
		col = i; 
	}
	cout << "\n" << "Cреднее арифметическое введенных точек = " << double(sum) / col;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int menu;
	std::cout << "Enter menu mode: ";
	std::cin >> menu;

	switch (menu) {
	case 1:
		task_1();
		break;
	case 2:
		task_2();
		break;
	case 3:
		task_3();
		break;
	case 4:
		std::cout << "Exit\n";
		break;
	default:
		std::cout << "Exit\n";
		break;
	}
}