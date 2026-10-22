#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 61 - 35;
    }
}

void Print(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(4) << mas[i];
    }
}

int Count(int mas[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0 || mas[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int Sum(int mas[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0 || mas[i] % 2 != 0) {
            sum += mas[i];
        }
    }
    return sum;
}

void Zero(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0 || mas[i] % 2 != 0) {
            mas[i] = 0;
        }
    }
}
#ifndef TESTING_MODE
int main() {
    srand((unsigned)time(0));
    const int n = 27;
    int c[n];

    Create(c, n);
    cout << "c = ";
    Print(c, n);
    cout << endl;

    int count = Count(c, n);
    int sum = Sum(c, n);

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    Zero(c, n);

    cout << "Modified c = ";
    Print(c, n);
    cout << endl;

    return 0;
}
#endif