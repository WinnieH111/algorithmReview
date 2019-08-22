#include <iostream>
#include <vector>

using namespace std;
// 3 different method to calculate Fibonacci number

// Recurssion 
int fib (int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1; 
    else {
        return fib(n-1) + fib(n-2);
    }
}

// Use a table
int fibTable (int n) {
    vector<int> numList(n+1, 0);
    numList.at(0) = 0;
    numList.at(1) = 1;
    for (int i=2; i<numList.size(); i++) {
        numList.at(i) = numList.at(i-1)+numList.at(i-2);
    }
    return numList.at(n);
}

int fibSpaceSaving (int n) {
    int loc0 = 0;
    int loc1 = 1;
    int loc2 = 0;
    for (int i=2; i<=n; i++) {
        loc2 = loc0+loc1;
        loc0 = loc1;
        loc1 = loc2;
    }
    return loc2;
}

int main()
{
    int n = fib(10);
    cout<<n<<endl;
    int n1 = fibTable(10);
    cout<<n1<<endl;
    int n2 = fibSpaceSaving(10);
    cout<<n2<<endl;
}
