
#include <iostream>
#include <cmath>
using namespace std;

class Base
{
private:
    int** masik;
    int str;
    int stlb;
    int size;
    int sum_pch = 0;
    int* tiny;
    int half_masik;
    int temp;
    int counter;
    int a = 0;
public:
    Base(){}
    void Massik(int str, int stlb) {
        masik = new int* [str];
        for (int i = 0; i < str; i++) {
            masik[i] = new int[stlb];
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stlb; j++) {
                masik[i][j] = rand() % 12 +1;
            }
        }
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stlb; j++) {
                cout << masik[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void CountProstieChisla(int str, int stlb) {

        for (int i = 0; i < str; i++) {

            for (int j = 0; j < stlb; j++) { // перебор массива
                counter = 0;
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
        cout << sum_pch << " - сумма простых чисел" << endl;
    }
    void StolbicVMassiv(int str, int stlb) {
        half_masik = str * stlb / 2;
        tiny = { new int[stlb] };
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
        }
    }
    void Sortirovka(int str, int stlb) {
        for (int i = 1; i < stlb; ++i){
            for (int r = 0; r < stlb - i; r++){
                if (tiny[r] < tiny[r + 1]){
                    // Обмен местами
                    int temp = tiny[r];
                    tiny[r] = tiny[r + 1];
                    tiny[r + 1] = temp;
                }
            }
        }

        /* отсортированный массив */
        cout << "Отсортированный столбик: ";
        for (int i = 0; i < stlb; ++i)
        {
            cout << tiny[i] << " ";
        }
        cout << endl;

    }

    ~Base() {

            delete[] masik;
            //функция создания массива
            //функция заполнения массива
            //функция выполняющая задание
            //Деструктор базового класса для очищения памяти для массива

    }
};

class Child : public Base // класс child наследуется от Base и имеет все те же функции, что и базовый класс
{
public:
    Child(int str, int stlb) {
        Massik(str, stlb);
        CountProstieChisla(str, stlb);
        StolbicVMassiv(str, stlb);
        Sortirovka(str, stlb);
    }

    //Конструктор вызывающий все функции внутри из базового класса
    //Деструктор производного класса

};

int main()
{
    setlocale(LC_ALL, "Russian");
    int str;
    cout << "Количество строк?: ";
    cin >> str;
    int stlb;
    cout << "Количество столбцов?: ";
    cin >> stlb;
    //ввод размерности массива
    //создание класса Child и вызов его конструктора
    Child a(str,stlb);
    return 0;
}