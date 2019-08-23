#include <iostream>
#include <vector>
using namespace std;

// Given a list of coin with specified values, given a target value
// Try to find the minimum number of coins can be used to reach the target value

int minCoins (vector<int> coins, int target) {
    vector<int> resultTable(target+1, target+1);
    resultTable.at(0) = 0;
    for(int i=1; i<resultTable.size(); i++) {
        for(int j=0; j<coins.size(); j++) {
            if (i - coins.at(j) < 0) continue;
            resultTable.at(i) = min(resultTable.at(i), 1+resultTable.at(i-coins.at(j)));
        }
    }
    return (resultTable.at(target) == target+1) ? -1: resultTable.at(target);
}


int main()
{
    vector<int> coins = {1,2,5};
    cout<<minCoins(coins, 11)<<endl;
}
