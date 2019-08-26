//TODO: Not working appropriately yet. Need to debug. 
//Recursion not ends. 

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&list, int start, int mid, int end) {
    
    
    vector<int> list1(mid-start+1, 0);
    vector<int> list2(end-mid, 0);
    
    //Copy the list into 2 seperated lists.
    for(int i=0; i<list1.size(); i++) {
        list1.at(i) = list.at(i);
    }
    for(int i=0; i<list2.size(); i++) {
        list2.at(i) = list.at(mid+i);
    }
    int i=0;
    int j=0;
    int k = start;
    while (i<list1.size() && j<list2.size()) {
        if(list1.at(i) <= list2.at(j)) {
            list.at(k) = list1.at(i);
            i++;
            k++;
        }
        else {
            list.at(k) = list2.at(j);
            j++;
            k++;
        }
    }
    if (i<list1.size()) {
        for(;i<list.size(); i++){
            list.at(k) = list1.at(i);
            k++;
        }
    }
    else if (j<list2.size()) {
        for(;j<list.size(); j++){
            list.at(k) = list1.at(j);
            k++;
        }
    }
    else {
        return;
    }
    
}

void mergeSort (vector<int>&list, int start, int end) {
    if (start < end) {
        int m = (start+end)/2+1;
        cout<<"m is "<<m<<endl;
        mergeSort(list, start, m);
        mergeSort(list, m+1, end);
        merge(list, start, m, end); 
    }
}

int main()
{
    vector<int> list{5, 1, 3, 2, 4, 8};
    
    mergeSort(list, 0, list.size()-1);
    
    for(int i=0; i<list.size(); i++) {
        cout<<list.at(i)<<" ";
    }
    return 0;
}


void mergeSort (vector<int>&list, int start, int end) {
    if (start < end) {
        int m = (start+end)/2+1;
        cout<<"m is "<<m<<endl;
        mergeSort(list, start, m);
        mergeSort(list, m+1, end);
        merge(list, start, m, end); 
    }
}

int main()
{
    vector<int> list{5, 1, 3, 2, 4, 8};
    
    mergeSort(list, 0, list.size()-1);
    
    for(int i=0; i<list.size(); i++) {
        cout<<list.at(i)<<" ";
    }
    return 0;
}
