#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateDels(string s){
    int iCount=0;
    for(int i=0;i<s.length();i++){
        if(i==s.length()-1) continue;
        if(s[i] == s[i+1]) iCount++;
    }
    return iCount;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int iNumTC;
    vector<string> v;
    string stemp;
    cin>>iNumTC;
    for(int i=0;i<iNumTC;i++){
        cin>>stemp;
        v.push_back(stemp);
    }
    for(int i=0;i<v.size();i++){
        cout<<calculateDels(v[i])<<endl;
    }
    return 0;
}