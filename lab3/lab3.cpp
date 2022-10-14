﻿#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;  //  функция меняет местами два элемента

void merge(int data[], const int start, const int stop, const int middle) {
    int first_array = start;    // старт, который можем изменять
    int second_array = middle;  // середина, которую можем изменять
    int tmp_arr[1000];    // массив, в которм хранится результат мёрджа
    int now_ctn = 0;            // счётчик

    while ((first_array < middle) || (second_array < stop)) {
        if (data[first_array] < data[second_array] && (first_array < middle) && (second_array < stop)) {
            tmp_arr[now_ctn] = data[first_array];
            first_array++;
        }
        else if ((first_array < middle) && (second_array < stop)) {
            tmp_arr[now_ctn] = data[second_array];
            second_array++;
            // хвостовые случаи
        }
        else if (first_array < middle) {
            tmp_arr[now_ctn] = data[first_array];
            first_array++;
        }
        else if (second_array < stop) {
            tmp_arr[now_ctn] = data[second_array];
            second_array++;
        }
        now_ctn++;
    }

    //заполнение исходного массива
    for (int i = start; i < stop; i++) {
        data[i] = tmp_arr[i - start];
    }
}

void merge_sort(int data[], int start, int stop) {
    if (stop - start <= 1) {
        return;  // у нас массив состоит из 1 элемента
    }
    else {
        int middle = start + (stop - start) / 2;

        merge_sort(data, start, middle);    // left array
        merge_sort(data, middle, stop);     // right array
        merge(data, start, stop, middle);   // merge 2 array
    }
}

void task_1(int mas[], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }

    cout << "Отсортированный массив : ";
    for (int i = 0; i < m; i++) {            //  Вывод идет через цикл т.к массив не выведется через cout 
        cout << mas[i] << " ";
    }
    cout << "\n";
}

void task_2(char mas[], int b) {
    int l[26];                                // 26 кол - во англ букв 
    for (int i = 0; i < 26; i++) {            // вспомогательный массив элементы которого мы обнуляем 
        l[i] = 0;
    }

    cout << "Отсортированный массив : ";
    for (int i = 0; i < b; i++) {
        l[int(mas[i] - 97)]++;                // a - 97 индекс по таблице аскела                       
    }
    for (int i = 0; i < 26; i++) {
        if (l[i] > 0) {
            for (int g = 0; g < l[i]; g++) {
                cout << char(97 + i) << " ";
            }
        }
    }
    cout << "\n";
}

void task_3(int mas[], const int lenght) { 
    merge_sort(mas, 0, lenght);

    cout << "Отсортированный массив : ";
    for (auto i = 0; i < lenght; i++) {
        cout << mas[i] << " ";
    }
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Выберите номер задания : ";
    int z;
    cin >> z;
    switch (z) {
    case 1:
        cout << "Введите размер массива (не больше 1000) : ";
        int m;
        cin >> m;
        cout << "Заполните массив : ";
        int M[1000];                                     // Размер массива
        for (int i = 0; i < m; i++) {
            cin >> M[i];
        }

        task_1(M, m);                                    // Передаем в функцию аргументы
        break;

    case 2:
        cout << "Введите размер массива (не более 1000) : ";
        int b;
        cin >> b;
        cout << "Введите символьный массив : " << endl;
        char L[1000];
        for (int i = 0; i < b; i++) {
            cin >> L[i];
        }

        task_2(L, b);   // Передаем в функцию аргументы
        break;

    case 3:
        int array[1000];                                     // Размер массива
        int len;
        cout << "Введите размер массива (не больше 1000) : ";
        cin >> len;
        cout << "Заполните массив : ";

        for (int i = 0; i < len; i++) {
            cin >> array[i];
        }

        task_3(array, len);                                    // Передаем в функцию аргументы
        break;
    }
}