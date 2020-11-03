#include<iostream>


int* init_stack(int n){
    int* tab= new int[n];
    return tab;
}

void delete_stack(int* tab){
    delete [] tab;
}
void print_stack(int* adrtop,int* tab){

    for (int i=0; i < *adrtop +1; i++) {
            std::cout << tab[i] << ' ' ;
        }
    std::cout <<'\n';
    }
