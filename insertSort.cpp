#include <iostream>

using namespace std;
void insertSort ( int arr[], int len ) {
    cout<<len<<endl;
    for (int i = 1; i<len; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertSort (arr, len);
    for (int i=0; i<len; i++) {
        cout<<arr[i]<<",";
    }
    cout<<endl;
    return 0;
}
