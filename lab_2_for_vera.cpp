
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a;
    cout << "Введите размерность матрицы: ";
    cin >> a;
        srand(time(NULL));
    int **array;
    array = new int* [a];
    for (int i = 0; i < a; i++){
        array[i] = new int [a];
    }

    for (int i = 0; i < a; i ++){
        for (int j = 0; j < a; j++){
            array[i][j] = rand()%20 -10;
        }
    }
    
    cout << "\nМатрица:\n";
    int summ = 0;
    for (int i = 0; i < a; i ++){
        for (int j = 0; j < a; j++){
            summ += array[i][j];
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    bool flag = 1;
    for(int i = 0; i < a - 1; i ++){
        if(array[i][i] > array[i+1][i+1]) continue;
        else{
            flag = 0;
        }
    }
    cout << flag << endl;
    if (flag == 1){
        for (int i = 0; i < a; i ++){
            for (int j = 0; j < a; j++){
                if(i < j && array[i][j] < 0) array[i][j] = 0;
            }
        }
        int new_summ = 0;
        cout << "Измененная матрица:\n";
        for(int i = 0; i < a; i ++){
            for (int j = 0; j < a; j++){
                new_summ += array[i][j];
                cout << array[i][j] << " ";
            }
            cout << endl;
        }    
    cout << "Сумма элементов изначальной матрицы = " << summ << endl;
    cout << "Измененная сумма = " << new_summ << endl;
    cout << "Сумма увеличилась на " << new_summ - summ << endl;
    }else cout << "Матрица не удовлетворяет условию ->  не изменяется." << endl;
    return 0;
}