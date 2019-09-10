#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isPalindrome(string s){
    string r=s;
    std::reverse(r.begin(), r.end());
    return s.compare(r);
}

int delToMakePalindrome(string s){
    if(isPalindrome(s) == 0) return 0;
    int l=s.length(), iCount=0;
    for(int i=0;i<l/2;i++){
        if(s[i] == s[l-1-i]) continue;
        if(s[i] > s[l-1-i]){
            while(1){
                if(s[i] == s[l-1-i]) break;
                if(s.at(i) > 'a'){
                    s[i] = s.at(i)-1;
                    iCount++;
                }else if(s.at(l-1-i) > 'a'){
                    s[l-1-i] = s.at(l-1-i)-1;
                    iCount++;
                } 
            }
        }else{
            while(1){
                if(s[i] == s[l-1-i]) break;
                if(s.at(l-1-i) > 'a'){
                    s[l-1-i] = s.at(l-1-i)-1;
                    iCount++;
                }else if(s.at(i) > 'a'){
                    s[i] = s.at(i)-1;
                    iCount++;
                }
            }
        }
    }
    return iCount;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iCount;
    vector<string> v;
    string stemp;
    cin>>iCount;
    for(int i=0;i<iCount;i++){
        cin>>stemp;
        v.push_back(stemp);
    }
    for(int i=0;i<v.size();i++)
        cout<<delToMakePalindrome(v[i])<<endl;
    return 0;
}
