#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
  int T; cin >> T;
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;
  while(T--) {
    double A; cin >> A;
    double B; cin >> B;
    double C; cin >> C;

    /* Enter your code here */
        std::cout.unsetf(std::ios_base::uppercase);

        std::cout<<std::hex
                 <<std::showbase
                 <<std::nouppercase
                 <<std::left
                 <<(long)A
                 <<std::endl;
        
        std::cout<<std::setfill('_')
                 <<std::setw(15)
                 <<std::setprecision(2)
                 <<std::fixed
                 <<std::right
                 <<std::showpos
                 <<B
                 <<std::endl;

        std::cout<<std::dec
                 <<std::scientific
                 <<std::setprecision(9)
                 <<std::uppercase
                 <<std::resetiosflags(ios::showpos)
                 <<C
                 <<std::endl;
  }
  return 0;

}