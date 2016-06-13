//
//  main.cpp
//  SwapsMerge
//
//  Created by Miguel Cuellar on 2/5/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//
int icont=0;
#include <iostream>
using namespace std;

void Une(int arr[], int emp, int mitad, int fin){
    
    int i, j, k, aux[50000];
    i = emp;
    k = emp;
    j = mitad + 1;
    while (i<=mitad&&j<=fin)
    {
        if (arr[i] < arr[j])
        {
            aux[k] = arr[i];
            k++;
            i++;
        }
        
        else
        {
            aux[k] = arr[j];
            k++;
            j++;
            icont += mitad-i + 1;
            //icont+=j;
        }
    }
    //Juntar arreglos
    while (i <= mitad)
    {
        aux[k] = arr[i];
        k++;
        i++;
        
    }
    while (j <= fin)
    {
        aux[k] = arr[j];
        k++;
        j++;
        
    }
    for (i = emp; i < k; i++)
    {
        arr[i] = aux[i];
    }
}

void mergeSort(int arr[], int emp, int fin)
{
    if (emp < fin)
    {
        int mitad = emp+(fin-emp)/2;
        mergeSort(arr, emp, mitad);
        mergeSort(arr, mitad+1, fin);
        Une(arr, emp, mitad, fin);
    }
}

int main()
{
    int arr[50000],n=1;
    cin>>n;
    while (n!=0) {
        icont=0;
        for (int ix=0; ix<n; ix++) {
            cin>>arr[ix];
        }
        mergeSort(arr, 0, n - 1);
        cout<<icont<<endl;
        cin>>n;
    }

    return 0;
}

