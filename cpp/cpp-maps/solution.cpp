#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    std::cin>>q;
    std::map<string,int> mDB={};
    std::string sName;
    int type, marks;
    for(int i=0;i<q;i++){
        std::cin>>type;
        switch(type){
            case 1:{
                std::cin>>sName>>marks;
                auto it = mDB.find(sName);
                if(it != mDB.end()){
                    mDB[sName] = it->second + marks;
                }else{
                    mDB.emplace(sName,marks);
                }
            }
            break;
            case 2:{
                std::cin>>sName;
                mDB.erase(sName);
            }
            break;
            case 3:{
                std::cin>>sName;
                auto it = mDB.find(sName);
                if(it != mDB.end()){
                    std::cout<<it->second<<std::endl;
                }else{
                    std::cout<<0<<std::endl;
                }
            }
            break;
            default:
            break;
        }
    }
    return 0;
}



