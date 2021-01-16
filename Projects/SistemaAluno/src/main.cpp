#include "Estudante.hpp"
#include <iostream> 
#include <algorithm>
#include <vector>
#include <bits/stdc++.h> 

void swap(float *xp, float *yp)  
{  
    float temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(float arr[2][10], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  {
        if (arr[0][j] > arr[0][j+1]) {  
            swap(&arr[0][j], &arr[0][j+1]);
            swap(&arr[1][j], &arr[1][j+1]); 
        } else if (arr[0][j] == arr[0][j+1])  {
            if(arr[1][j] < arr[1][j+1]) {
                swap(&arr[0][j], &arr[0][j+1]);
                swap(&arr[1][j], &arr[1][j+1]); 
            }
        }
    }
}  

int main() {
    int rows = 10;
    Estudante* vectorStudents[10];
    float two_d[2][10];
    for(int i=0; i< rows; i++) {
        vectorStudents[i] = new Estudante;
        std::cin >> vectorStudents[i]->matricula;
        std::cin >> vectorStudents[i]->nome;
        for(int j = 0; j < 5; j++ ) {
            std::cin >> vectorStudents[i]->notas[j];
        }
        two_d[1][i] = vectorStudents[i]->matricula;
        two_d[0][i] = vectorStudents[i]->calcularRSG();
    }
    
    bubbleSort(two_d, rows);
    float arr[3] = {two_d[1][9], two_d[1][8], two_d[1][7]};
    
    for(int j=0; j < 3; j++) {
        for(int i=0; i< rows; i++) {
            if (vectorStudents[i]->matricula == arr[j]){ 
                std::cout << vectorStudents[i]->matricula << " ";
                std::cout << vectorStudents[i]->nome << " ";
                std::cout << std::fixed << std::setprecision(2) << vectorStudents[i]->calcularRSG() << std::endl; 
            }
        }
        
    }
    return 0;
    
}