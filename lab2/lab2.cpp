#include <iostream> 
#include <string> 

void task_1() {
	int num;
	std::cout << "Enter num: ";
	std::cin >> num;
	std::cout << "Num: " << num << "\n";
	std::string line;
	for (int i = 0; i <= num; i++) {
		line += std::to_string(i);
		std::cout << line << "\n";
	}
}

void task_2() {
	int n;
	unsigned long long Cnk = 1;

	std::cout << "Введите число n: ";
	std::cin >> n;
	std::cout << "Ваши биноминальные коэфиценты\n";

	for (int k = 1; k <= n + 1; k++) {
		std::cout << Cnk << " ";
		Cnk = Cnk * (n + 1 - k) / k;
	}
	std::cout << "\n";
}

void task_3() {
	std::string s_num;
	int ctn = 0;
	int summ = 0;

	std::cout << "Enter num[0]: ";
	std::cin >> s_num;
	while (s_num != "-") {
		summ += std::atoi(s_num.c_str());
		ctn++;

		std::cout << "Enter num[" << ctn << "]: ";
		std::cin >> s_num;
	}

	std::cout << double(summ) / ctn << "\n";
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