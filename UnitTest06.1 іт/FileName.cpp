#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи: передаємо масив mas, розмір n та поточний індекс i
void Create(int mas[], const int n, int i);
void Print(int mas[], const int n, int i);
int Count(int mas[], const int n, int i);
int Sum(int mas[], const int n, int i);
void Zero(int mas[], const int n, int i);

int main() {
    srand((unsigned)time(0));
    const int n = 20;
    int a[n];

    // У рекурсії передаємо початковий індекс 0
    Create(a, n, 0);
    cout << "a = ";
    Print(a, n, 0);
    cout << endl;

    int count = Count(a, n, 0);
    int sum = Sum(a, n, 0);

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    Zero(a, n, 0);

    cout << "Modified a = ";
    Print(a, n, 0);
    cout << endl;

    return 0;
}

// 1. Заповнення
void Create(int mas[], const int n, int i) {
    if (i < n) {
        mas[i] = rand() % 71 - 20;
        Create(mas, n, i + 1); // ідемо до наступного елемента
    }
}

// 2. Друк
void Print(int mas[], const int n, int i) {
    if (i < n) {
        cout << mas[i] << " ";
        Print(mas, n, i + 1);
    }
}

// 3. Кількість
int Count(int mas[], const int n, int i) {
    if (i >= n) return 0; // База рекурсії: коли дійшли до кінця, повертаємо 0

    if (mas[i] > 0 && i % 5 != 0)
        return 1 + Count(mas, n, i + 1); // Знайшли елемент (+1) і йдемо далі
    else
        return Count(mas, n, i + 1);    // Елемент не підійшов (+0), просто йдемо далі
}

// 4. Сума
int Sum(int mas[], const int n, int i) {
    if (i >= n) return 0; // База рекурсії

    if (mas[i] > 0 && i % 5 != 0)
        return mas[i] + Sum(mas, n, i + 1); // Додаємо значення елемента і йдемо далі
    else
        return Sum(mas, n, i + 1);          // Пропускаємо елемент і йдемо далі
}

// 5. Обнулення
void Zero(int mas[], const int n, int i) {
    if (i < n) {
        if (mas[i] > 0 && i % 5 != 0) {
            mas[i] = 0;
        }
        Zero(mas, n, i + 1); // ідемо далі
    }
}