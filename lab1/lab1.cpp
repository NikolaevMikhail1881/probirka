#include <iostream>
#include <bitset>

using std::cin;
using std::cout;

void t1() {
	cout << "Nikolaev Mikhail Artemovich, 221-352\n\n";
}

void t2() {
	cout << "min int=" << INT_MIN
		<< "\t\t\tmax int=" << INT_MAX
		<< "\t\t\tsize of int=" << sizeof(int) << "\n";
	cout << "min unsigned int=" << 0
		<< "\t\t\tmax unsigned int=" << UINT_MAX
		<< "\t\tsize of unsigned int=" << sizeof(unsigned) << "\n";
	cout << "min short=" << SHRT_MIN
		<< "\t\t\tmax short=" << SHRT_MAX
		<< "\t\t\t\tsize of short=" << sizeof(short) << "\n";
	cout << "min unsigned short=" << 0
		<< "\t\t\tmax unsigned short=" << USHRT_MAX
		<< "\t\tsize of unsigned short=" << sizeof(unsigned short) << "\n";
	cout << "min long=" << LONG_MIN
		<< "\t\t\tmax long=" << LONG_MAX
		<< "\t\t\tsize of long=" << sizeof(long) << "\n";
	cout << "min long long=" << LLONG_MIN
		<< "\tmax long long=" << LLONG_MAX
		<< "\tsize of long long=" << sizeof(long long) << "\n";
	cout << "min double=" << DBL_MIN
		<< "\t\t\tmax double=" << DBL_MAX
		<< "\t\t\tsize of double=" << sizeof(double) << "\n";
	cout << "min char=" << CHAR_MIN
		<< "\t\t\t\tmax char=" << CHAR_MAX
		<< "\t\t\t\tsize of char=" << sizeof(char) << "\n";
	cout << "min bool=" << 0
		<< "\t\t\t\tmax bool=" << 1
		<< "\t\t\t\tsize of bool=" << sizeof(bool) << "\n\n";
}

void t3() {
	int n;
	cout << "Your num :";
	cin >> n;
	cout << "bin :" << std::bitset < 8 * sizeof(n)>(n) << "\n";
	cout << "hex :" << std::hex << n << std::dec << "\n";
	cout << "bool :" << bool(n) << "\n";
	cout << "char :" << char(n) << "\n";
	cout << "double :" << double(n) << "\n\n";
}

void t4() {
	int d, f;
	cout << "enter d and f: ";
	cin >> d >> f;
	cout << d << "*x=" << f << "\n";
	cout << "x=" << f << "/" << d << "\n";
	cout << "x=" << double(f) / d << "\n\n";
}

void t5() {
	double l, m;
	cout << "Enter l and m: ";
	cin >> l >> m;
	cout << (l + m) / 2 << "\n";
}

int main()
{
	t1();
	t2();
	t3();
	t4();
	t5();
}