// lab 2
#include <iostream> 


using std::cin; 
using std::cout;


void task_1() {
	int m;
	cout << "Введите число: ";
	cin >> m;
	for (int i = 0; i <= m; i++) {           // Объявляем и инициализируем переменную в цикле for, вводим условие 
		for (int j = 0; j <= i; j++) {
			cout << j;

		}
		cout << "\n";
	}
}
  double fact(int b) {     // double (увеличенный промежуток c плавающей точкой) - т.к будут факториалы 
	if (b == 0) return 1;	// возвращаемое значение 
	double k = 1;
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
		sum = sum + x;         // sum = сумма вводимых чисел; col = i =  количество вводимых чисел (для счета среднего)
		col = i; 
	}
	cout << "\n" << "Cреднее арифметическое введенных точек = " << double(sum) / col;  // явное преобразование (может получитсья нецелое число))
}

int main()
{
	setlocale(LC_ALL, "RU"); // подключаем русский язык 
	int menu;
	cout << "Enter menu mode: ";
	cin >> menu;

	switch (menu) {      // используем switch - case для меню выбора задания 
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
		cout << "Exit\n";
		break;
	default:
		cout << "Exit\n";
		break;
	}
}

/*
void sort(mas,left,right)
{
условие остановки
	sort(mas,left,(left+right)/2);
	sort(mas,(left+right)/2+1,right);
	merge(mas,left,right);
}

void merge(mas,left,right)
{
	сливаем обе половины
}

*/