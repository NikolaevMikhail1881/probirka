#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap; 

void task_1(int arr[], int r) {
	cout << "Заполните массив : ";
	for (int i = 0; i < r; i++) {
		cin >> arr[i];                     // заполнение массива 
	}
}

void task_2(int arr[], int r) {
	for (int i = 0; i < r; i++) {
		cout << arr[i] << " ";           // вывод массива
	}
	cout << endl; 
}

//void task_3(int arr[], int r) {
//	int* vsp = new int[r];                  // вспомогательный массив 
//	for (int i = 0; i < r; i+=2) {          // i+=2 потому что идем только по четным числам начиная с 0 
//		int sum = 0;                        // обнудяем сумму
//		int elem = arr[i];                  // elem приравниваем к элементу массиву arr c индексом i
//		vsp[i] = arr[i];                    // i элемент вспомогательного массива приравниваем к i элементу массива arr
//		while (elem / 10 > 0 || (elem < 10 && elem > 0)) {                // цикл while
//			sum += elem % 10;
//			elem /= 10;
//		}
//		vsp[i + 1] = sum;                    // сумма цифр пред. элемента
//	}
//
//	
//	/*cout << "Вспомогательный массив \n";
//	for (int i = 0; i < r+1; i++) {
//		cout << vsp[i] << " ";
//	}
//	cout << endl;*/
//
//	for (int i = 0; i < r; i+=2) {                  // i+=2 идем по четным элементам (на них стоят сами числа а не их суммы)
//		for (int j = 0; j < r - i - 2; j+=2) {      // r - i -2 чтобы не выйти за границы 
//			if (vsp[j+1] > vsp[j+3]) {
//				swap(vsp[j + 1], vsp[j + 3]);
//				swap(vsp[j], vsp[j + 2]);
//			}
//		}
//	}
//	/*cout << "Отсортированный вспомогательный массив \n";
//	for (int i = 0; i < r+1; i++) {                             
//		cout << vsp[i] << " ";
//	}*/
//	cout << "Отсортированный исходный массив : \n";
//	for (int i = 0; i < r; i++) {
//		if (i % 2 == 0) {
//			arr[i] = vsp[i]; 
//		}
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}

void task_3(int arr[], int r) {
	int* vsp = new int[2 * r];                    // вспомогательный массив   
	int sch = 0;         // счетчик                         // 2 * r  т.к идем только по сумме его четных цифр 
	for (int i = 0; i < 2 * r; i += 2) {          
		int sum = 0;                              // обнуляем сумму
		int elem = arr[sch];                      // elem приравниваем к элемент r счетчику 
		vsp[i] = arr[sch];                        // i элемент вспомогательного массива приравниваем к элементу массива с индексом счетчика 
		for (int j = 0; elem / 10 > 0 || (elem > 0 && elem < 10); j++) {
			if (j % 2 == 0) {
				sum += elem % 10;
				elem /= 10;

			}
			else{
				elem /= 10; 
			}
		}
		vsp[i + 1] = sum;                         // сумма цифр пред. элемента
		sch++;
	} 
	cout << "ВСП : ";
	for (int i = 0; i < 2 * r; i++) {
		cout << vsp[i] << " ";
	}
	cout << endl; 


	/*cout << "Вспомогательный массив \n";
	for (int i = 0; i < r+1; i++) {
		cout << vsp[i] << " ";
	}
	cout << endl;*/

	for (int i = 0; i < 2 * r; i += 2) {                  // i+=2 идем по четным элементам (на них стоят сами числа а не их суммы)
		for (int j = 0; j < 2 * r - i - 2; j += 2) {      // r - i -2 чтобы не выйти за границы 
			if (vsp[j + 1] > vsp[j + 3]) {
				swap(vsp[j + 1], vsp[j + 3]);
				swap(vsp[j], vsp[j + 2]);
			}
		}
	}
	/*cout << "Отсортированный вспомогательный массив \n";
	for (int i = 0; i < r+1; i++) {
		cout << vsp[i] << " ";
	}*/
	cout << "Отсортированный исходный массив : \n";
	for (int i = 0; i < 2 * r; i+=2) {
		
		cout << vsp[i] << " ";
	}
	cout << endl;
}


void task_4(int arr[], int r) {
	int* vsp = new int[2 * r];                     // Вспомогательный массив умноженный на 2 т.к он будет в два раза больше 
	int sch = 0;                                   // cчетчик 
	for (int i = 0; i < 2 * r; i+=2) {
		vsp[i] = arr[sch]; 
		vsp[i + 1] = arr[sch] % 10; 
		sch++;
	}
	/*for (int i = 0; i < 2 * r; i++) {
		cout << vsp[i] << " ";
	}
	cout << endl; */

	for (int i = 0; i < 2 * r; i += 2) {                  // i+=2 идем по четным элементам (на них стоят сами числа а не их суммы)
		for (int j = 0; j < 2 * r - i - 2; j += 2) {      // r - i -2 чтобы не выйти за границы 
			if (vsp[j + 1] > vsp[j + 3]) {
				swap(vsp[j + 1], vsp[j + 3]);
				swap(vsp[j], vsp[j + 2]);
			}
			else if (vsp[j + 1] == vsp[j + 3]) {
				if (vsp[j] > vsp[j + 2]) {
					swap(vsp[j], vsp[j + 2]);
				}
			}
		}
	}
	/*cout << "Отсортированный вспомогательный массив : ";
	for (int i = 0; i < 2 * r; i++) {
		cout << vsp[i] << " ";
	}*/
	cout << "Отсортированный массив : ";
	for (int i = 0; i < 2 * r; i+=2) {
		cout << vsp[i] << " "; 
	}
	cout << endl;
}




int main() {
	setlocale(LC_ALL, "RU");
	int n;
	bool flag = true;

	cout << "Введите размер массива : ";
	int r;
	cin >> r;                         // размер массива определяет пользователь 
	int* arr = new int[r];           // создаем ссылку на область памяти для хранение элементов (массива)

	while (flag) {
		
		cout << "Введите 5 для выхода* \n";
		cout << "Введите номер задания : ";
		cin >> n;


		switch (n) {
		case 1:
			task_1(arr, r);               // передаем arr и r в task_1
			break;
		case 2:
			task_2(arr,r);               // передаем arr и r в task_2
			break;
		case 3:
			task_3(arr, r);
			break;
		case 4:
			task_4(arr, r);
			break;
		case 5:
			flag = false;     // если выбрать 5 то флаг станет false и мы получим выход из программы
			break;
		


		}
	}
}









