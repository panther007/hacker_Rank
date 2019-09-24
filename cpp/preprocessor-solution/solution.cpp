/* Enter your macros here */

#define INF 1
#define toStr(X) #X

#define io(Y) std::cin>>Y

#define FUNCTION(A, B) \
        void A(int& n, int m){\
            if(m B n){\
                n = m;\
            }\
        }\

#define foreach(R, T) \
        for(int T=0;T<R.size();T++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}