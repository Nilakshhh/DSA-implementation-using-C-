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
