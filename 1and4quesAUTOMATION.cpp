#include <iostream>
using namespace std;

// задание 1: заполнение матрицы по спирали 
void task1(int m, int n) {
    int matrix[m][n];
    int num = 1, top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // слева направо
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // сверху вниз
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // справа налево
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // снизу вверх
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    // вывод матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// задание 4: заполнение матрицы по периметру
void task4(int m, int n) {
    int matrix[m][n];
    int value = 1;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // верхний периметр
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value;
        }
        top++;

        // правый периметр
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value;
        }
        right--;

        // нижний периметр
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value;
            }
            bottom--;
        }

        // левый периметр
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value;
            }
            left++;
        }
        value++;
    }

    // вывод матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    while (true) {
        cout << "выберите задание (1 или 4) или 0 для выхода: ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            int m, n;
            cout << "введите размеры матрицы (m и n): ";
            cin >> m >> n;
            task1(m, n);
        } else if (choice == 4) {
            int m, n;
            cout << "введите размеры матрицы (m и n): ";
            cin >> m >> n;
            task4(m, n);
        }
    }
    return 0;
}
