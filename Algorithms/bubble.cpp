#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(array[j]>array[j+1])
               swap(array[j],array[j+1]);


        }
    }
}

void print_array(int array[], int n){
    for(int i=0; i<n; i++)
        cout << " " << array[i];

}

void output(int array[], int n)
{
    bubbleSort(array, n);
}
int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n ; i++)
    cin >> array[i];
    output(array, n);
    //bubbleSort(array, n);
    print_array(array, n);
    return 0;
}

