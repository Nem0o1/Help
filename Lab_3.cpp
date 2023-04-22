#include <iostream>

using namespace std;


class Base{
    protected:
    int **array;
    public:
    Base(){
    }
    void creator(int x, int y);
    void aggregate(int x, int y);
    void task(int x, int y);
};


class Child: public Base{
    public:
    
    Child(int a, int b){
        creator(a,b);
        aggregate(a, b);
        task(a, b);
    }
};


int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int x, y;
    cin >> x >> y;
    Child a(x,y);
    return 0;
}


void Base::aggregate(int x, int y){
        for (int i = 0; i < x; i ++){
            for (int j = 0; j < y; j++){
                array[i][j] = rand() % 20 - 10;
            }
        }
        for (int i = 0; i < x; i ++){
            for (int j = 0; j < y; j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
}


void Base::creator(int x, int y){
        array = new int* [x];
        for (int i = 0; i < x; i++){
            array[i] = new int [y];
        }
}


void Base::task(int x, int y){
    int sred = 0;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if(j > i) sred += array[i][j];
        }
    }
    cout << "Среднее арифметическое элементов над главной диагональю = " << sred << endl;
    int a = 0, naim = 0;
    for (int i = 0; i < x; i++){
        for (int j = 0; j <y; j++){
            naim += array[i][j];
        }
        a = min(naim, a);
        naim = 0;
    }
    naim = 0;
    cout << "Наименьшая сумма элементов в строке = " << a << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            naim += array[i][j];
        }
        if (naim == a) {
            naim = i;
            break;
        }else naim = 0;
    }
    cout << "Номер строки с наименьшей суммой эл-тов = " << naim << endl;

    for (int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i == naim){
                array[i][j] +=sred;
            }
        }
    }
    cout << "Изменненая матрица:" << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}