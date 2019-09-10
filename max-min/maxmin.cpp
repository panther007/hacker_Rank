#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* The code required to enter n,k, candies is provided*/

    int N, K, unfairness=0;
    cin >> N >> K;
    int iTemp;
    vector<int> candies;
    for (int i=0; i<N; i++){
        cin >> iTemp;
        candies.push_back(iTemp);
    }
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    std::sort(candies.begin(), candies.end());
    unfairness = candies[K-1] - candies[0];
    for (int i=1; i<candies.size(); i++){
        if( (i+K-1) >= candies.size()) continue;
        if( (candies[i+K-1] - candies[i]) < unfairness) 
            unfairness = candies[i+K-1] - candies[i];
    }
    
    //unfairness = calcUnfairness(candies, K);
    cout << unfairness << "\n";
    return 0;
}