#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int isPalindromPossible(string s){
    int iA[26], iB[26], pos, iCount=0;
    for(int i=0;i<26;i++) iA[i]=0;
    for(int i=0;i<26;i++) iB[i]=0;
    
    for(int i=0;i<s.length();i++){
        pos = s.at(i)-97;
        iA[pos]++;
        iB[pos] = (iA[pos] % 2);
    }
    
    
    for(int j=0;j<26;j++){
        if( (iB[j] % 2) == 1 ){
            iCount++;
        }
    }
    
    if( ((s.length() % 2) == 1) && (iCount  != 1 ) ){
        return 0;
    }else if( ((s.length() % 2) == 0) && (iCount != 0) ){
        return 0;
    }
    
    return 1;
}

int main() {
   
    string s;
    cin>>s;
     
    int flag = isPalindromPossible(s);
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
