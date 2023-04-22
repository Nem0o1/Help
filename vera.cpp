#include <iostream>

using namespace std;

void pervoezadanie(int** mass, int num);

int main()
{   
    srand(time(0));
    int num = 3;
    int** mass = new int* [num];
    for (int i = 0; i < 3; i++){
        mass[i] = new int [num];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mass[i][j] = rand() % 14 + 1; 
        }
    }
    pervoezadanie(mass, num);
    return 0;
}
void pervoezadanie(int** mass, int num){
    int polozit_el=0;
    int otrizat_el=0;
    int summ_polozit_el=0;
    int proizved_otriz_el=0;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout<<mass[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (mass[i][j]>=0){
                polozit_el++;
                summ_polozit_el=summ_polozit_el+mass[i][j];
            }
            else{ 
                otrizat_el++;
                proizved_otriz_el=proizved_otriz_el*mass[i][j];
            }
        }
        }
    if (polozit_el>otrizat_el){
        cout<<"Сумма положительных = "<<summ_polozit_el << endl;
    }else if(polozit_el<otrizat_el){
        cout<<"Произведение отрицательных = "<<proizved_otriz_el << endl;
    }
    else{
        cout<<"Положительных и отрицательных одинаково";
    }
    
}