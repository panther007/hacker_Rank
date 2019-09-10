#include <iostream>
using namespace std;

int treeHeight = 1;

int height(int n) {
    int h = 1;
    if(n==0) return h;
    for(int i=0;i<n;i++){
        if(i%2)
            h += 1;
        else
            h *= 2;
    }
    return h;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}