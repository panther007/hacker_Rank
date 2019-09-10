#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int iListSize;
    unsigned long long temp_i;
    vector<int> v;
    cin>>iListSize;
    for(int i=0;i<iListSize;i++){
        cin>>temp_i;
        cout<<(unsigned long long)pow(2,32)-temp_i-1<<endl;
    }
    return 0;
}