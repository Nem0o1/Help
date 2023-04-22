#include <cmath>
#include <iostream>
using namespace std;
int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int str;
    cout << "Количество строк?: ";
    cin >> str;
    int stlb;
    cout << "Количество столбцов?: ";
    cin >> stlb;
    int** masik = new int* [str];
    for (int i = 0; i < str; i++) {
        masik[i] = new int[stlb];
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stlb; j++) {
            masik[i][j] = rand() % 12+1;
        }
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stlb; j++) {
            cout << masik[i][j] << "\t";
        }
        cout << endl;
    }
    int sum_pch = 0; // сумма простых чисел
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stlb; j++) { // перебор массива
            int counter = 0;
            for (int m = 1; m < (masik[i][j] / 2 + 1); m++) {
                if (masik[i][j] % m == 0) {
                    counter++;
                }
            }
                if (counter == 1) {
                    cout << masik[i][j] << "- Простое число" << endl;
                    sum_pch++;
                }
                else {
                    cout << masik[i][j] << "- Составное число" << endl;
                }
            
}
        }
    cout << sum_pch << " - Количество простых чисел" << endl;
    int half_masik = str * stlb / 2;
    int* tiny{ new int[stlb] };
    if (sum_pch >= half_masik) {
        for (int i = 0; i < str; i++) {
                tiny[i] = masik[i][stlb - 1];
            }
        cout << "Последний столбик: ";
        for (int i = 0; i < stlb; ++i)
        {
            cout << tiny[i] << " ";
        }
        cout << endl;
        
    for (int i = 1; i < stlb; ++i)
    {
        for (int r = 0; r < stlb - i; r++)
        {
            if (tiny[r] < tiny[r + 1])
            {
                // Обмен местами
                int temp = tiny[r];
                tiny[r] = tiny[r + 1];
                tiny[r + 1] = temp;
            }
        }
    }
    
    /* Выведем отсортированный массив */
    cout << "Отсортированный столбик: ";
    for (int i = 0; i < stlb; ++i)
    {
        cout << tiny[i] << " ";
    }
    cout << endl;
    }
    return 0;
    }