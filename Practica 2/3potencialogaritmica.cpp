#include <iostream>
#include <vector>
using namespace std;

int pot(int a, int n) {
    if (n == 0) return 1;
    int x = pot(a, n/2);
    if (n % 2 == 0) return x*x;
    return x*x*a;
} 

/* 
a^n {

 1                ,   Si n es 0   

 (a^(n/2))^2      ,   Si n es par

 (a^((n-1)/2))^2  ,   Si n es impar

}

T(n) = 1*T(n/2) + O(1)

a = 1
b = 2
c = 0

d = b^c = 1

O ( n^0 log n) == O(log n) 

*/

int main() {

    cout << pot(2,9);

    return 0;
}
