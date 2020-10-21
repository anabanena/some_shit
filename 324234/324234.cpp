#include <iostream>
#include <clocale>
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~Задание 1~~~~~~~~~~~~~~~~~~~~~~~~~~~//

int gcd(int a, int b) { //greatest common divisitor/нод
    if (b == 0) return a;    
    else  gcd(b, a % b);
}

int lcm(int a, int b ) { //least common multiplier/нок
    return a *b /gcd(a,b);
}

void Task1() {

    cout << "Используя алгоритм Евклида, найти НОД и НОК двух натуральных чисел, введенных с клавиатуры." <<endl;
    
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Для чисел " << a << " и " << b << ", НОД = " << gcd(a, b) << ", а НОК = " << lcm(a,b) <<endl;

}

//~~~~~~~~~~~~~~~~~~~~~~~~Задание 2~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void calcAndPrint(float *num, int n) { //среднее значение
    float sum = 0;
    float sumOfSquares = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i];
        sumOfSquares += num[i] * num[i];
    }
    float mean = sum / n;
    float dispersion = sumOfSquares / n - mean*mean;
    float sko = sqrt(dispersion);

    cout << "Среднее значение: " << mean << ", дисперсия: " << dispersion << ", СКО: " << sko << endl;

}

void Task2() {

    cout << "Найти среднее значение, дисперсию и среднее квадратическое отклонение N чисел с плавающей точкой, введенных с клавиатуры (N < 1000)." << endl;

    int n;
    cout << "Введите количество чисел (до 1000): ";
    cin >> n;
    if (n < 1000) {
        float* mass = new float[n];
        cout << "Вводите ВЕЩЕСТВЕННЫЕ числа (ввод числа заканчивайте ENTER)\n";
        for (int i = 0; i < n; i++) {
            cin >> mass[i];
        }
        calcAndPrint(mass, n);
    }
 }

//~~~~~~~~~~~~~~~~~~~~~~~~Задание 3~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Task3() {

    cout << "Заполнить список из N(N < 100 ввести с клавиатуры) целых чисел случайными числами и найти максимальное и минимальное из них.Массив вывести на экран в строку." << endl;
    
    int n, min, max;
    cout << "Введите количество чисел (до 100): ";
    cin >> n;
    int* mass = new int[n];
    cout << "Полученный массив: " << endl;
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % n; //range 0 to n
        cout << mass[i] << " ";
    }
    cout << endl;
    min = mass[0];
    max = mass[0];

    for (int i = 1; i < n; i++) {
        if (mass[i] > max) max = mass[i];
        else if (mass[i] < min) min = mass[i];
    }

    cout << "Максимальное значение: " << max << ", минимальное значение: " << min << "." <<endl;

}

//~~~~~~~~~~~~~~~~~~~~~~~~Задание 4~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Task4() {

    cout << "Заполнить список из N (N < 1000 ввести с клавиатуры) целых чисел случайными числами и “перевернуть” - то есть поменять местами все элементы: первый с последним и т.д. Исходный и результирующий массивы вывести на экран. Использовать один массив." << endl;

    int n;
    cout << "Введите количество чисел (до 1000): ";
    cin >> n;
    if (n < 1000){
        int* mass = new int[n];
        cout << "Исходный массив: "<<endl;
        for (int i = 0; i < n; i++) {
            mass[i] = rand() % n; //range 0 to n
            cout << mass[i] << " ";
        }
        cout << endl;
        for (int i = 0, j = n - 1; i <= n / 2, j >= n / 2; i++, j--) {
            int temp = mass[i];
            mass[i] = mass[j];
            mass[j] = temp;
        }
        cout << "Результирующий массив: "<<endl;
        for (int i = 0; i < n; i++) {
            cout << mass[i] << " ";
        }
    }

    cout << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~Задание 5~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Task5() {

    cout << "Заполнить квадратную матрицу N*N (N < 10 ввести с клавиатуры) целыми числами. Вывести на экран матрицу и суммы элементов главной и побочной диагонали." << endl;

    int n, sum1 = 0, sum2 = 0;
    cout << "Ведите размерность матрицы (до 10): ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    cout << "Полученная матрица: " << endl;
    for (int i = 0; i < n; i++) { //заполнение матрицы случайными числами
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; 
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) sum1 += matrix[i][j];
            if (i + j == n - 1) sum2 += matrix[i][j];
        }
    }

    cout << "Сумма элементов главногй диагонали: " << sum1 << endl;
    cout << "Сумма элементов побочной диагонали: " << sum2 << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;

    while (true) {
        cout << "Выберете задачу (введите число от 1 до 5): ";
        cin >> n;
        switch (n) {
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 3: Task3(); break;
        case 4: Task4(); break;
        case 5: Task5(); break;
        default: return false;
        }
        
    }
    return 0;
}

