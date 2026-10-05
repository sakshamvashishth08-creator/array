#include <stdio.h>
int p_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
int partetion(int A[],int low,int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    while(i < j) {

        while(i <= high && A[i] <= pivot) {
            i++;
        }

        while(j >= low && A[j] > pivot) {
            j--;
        }

        if(i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;

}

void Quicksort(int A[],int low,int high){
    int q;
    if(low<high){
        q=partetion(A,low,high);
        Quicksort(A,low,q-1);
        Quicksort(A,q+1,high);
    }
}
int main(){
    int A[100]={1,5,23,5,325,54};
    int n=6;
    p_array(A,n);
    Quicksort(A,0,n-1);
    printf("\n");
    p_array(A,n);
    return 0;
}

