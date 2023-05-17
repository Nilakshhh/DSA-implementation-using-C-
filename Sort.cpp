#include <iostream>

using namespace std;

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(a[j]<a[j-1] && j>0){
            swap(a[j], a[j-1]);
            j--;
        }
    }
}

void bubbleSort(int a[], int n){
    int k=n;
    bool swapped = false;
    while(k>0){
        swapped = false;
        for(int i=0;i<k;i++){
           for(int j=i+1;j<n;j++){
               if(a[j]<a[j-1]){
                   swap(a[j], a[j-1]);
                   swapped = true;
               }
           }
        }
    k--;
    if(swapped == false){
        break;
    }
    }
}

void selectionSort(int a[], int n){
    for(int i=0;i<n;i++){
            int m = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]){
                m=j;
            }
        }
        swap(a[i], a[m]);
    }

}

helperQuick(int a[], int low, int high){
    int i=low-1;
    int piv = a[high];
    for(int j=low;j<high;j++){
        if(piv>a[j]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;

}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pi = helperQuick(a, low, high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
