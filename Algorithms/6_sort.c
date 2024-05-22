#include<stdio.h>



void print_array(int *array, int n){
    for(int i=0; i<n; i++)printf("%d  ",array[i]);
    printf("\n");
}

void arrayswop(int *array, int i, int j){
    int temp = array[i];
    array[i]= array[j];
    array[j]= temp;

}

void bubbleSort(int *array, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){\
            if(array[j]>array[j+1])
                arrayswop(array, j, j+1);

        }
    }
}

void insertionSort(int *array, int n){
    for(int i=1; i<n; i++){
        int j=i-1;
        int temp = array[i];
        while(array[j]>temp && j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void selectionSort(int *array, int n){
    for(int i=0; i<n-1; i++){
        int temp = i;
        for(int j=i+1;j<n; j++){
            if(array[temp]>array[j])temp=j;
        }
       //  swap(array[i], array[temp]);
        arrayswop(array, i, temp);
    }
}

void meargeSort(int *array, int L, int R){
    if(R-L>1){
        int mid = L + (R - L)/2;
        meargeSort(array, L, mid);
        meargeSort(array, mid, R);

        int i=L,j=mid,k=0;
        int temp[R-L];
        while(i<mid && j<R){
            if (array[i] < array[j])
                temp[k++] = array[i++];
            else
            temp[k++] = array[j++];
        }
        while(i<mid)
            temp[k++] = array[i++];
        while(j<R)
        temp[k++] = array[j++];
        if(R-L>1)
        for(int i=0; i<k;i++)
        array[L+i]=temp[i];
    }
}

int partition(int *array, int start, int end, int n){
    int pivot_index = start;
    int pivot = array[pivot_index];
    while(start< end){
        while(start<n && pivot >= array[start])start++;
        while(pivot < array[end])end--;
        if(start< end)arrayswop(array, start, end);
    }
    //swap(array[pivot_index], array[end]);
    arrayswop(array, pivot_index, end);
    return end;

}

void quickSort(int *array, int start, int end, int n){
    if(start < end){
        int p = partition(array, start, end, n);
        quickSort(array, start, p-1, n);
        quickSort(array, p+1, end, n);
    }
}

void heapify(int *array, int n, int p){
    int largest = p;
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    if(l < n && array[largest] < array[l])largest = l;
    if(r < n && array[largest] < array[r])largest = r;
    if(largest != p){
        //swap(array[largest], array[p]);
        arrayswop(array, largest, p);
        heapify(array, n, largest);
    }

}

void heapSort(int *array, int n){
    for(int i=n/2-1; i>=0; i--)heapify(array, n, i);
    for(int i=n-1; i>0; i--){
        //swap(array[i], array[0]);
        arrayswop(array, i, 0);
        heapify(array, i, 0);
    }

}


// main code, where you will give input.
//array means array
//n means number of elements / array size

void solve(int *array, int n){
    // bubbleSort(array, n);
    // insertionSort(array, n);
    selectionSort(array, n);
    // meargeSort(array, 0, n);

    // quickSort(array, 0, n-1, n);
    // heapSort(array, n);
    // print_array(array, n);
}



int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0; i<n ; i++)
        scanf("%d",&array[i]);

    solve(array, n);   // input going
    print_array(array, n);   //output print
    return 0;
}
