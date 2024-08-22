#include <iostream>
#include <vector>

using namespace std;

bool sumaSubconjunto(vector<int> c, int i, int j) {

    if(i == 0){
        return (j == 0);
    } 
    if(i != 0 &&  c[i] > j ){
        return sumaSubconjunto(c, i-1,j);
    } 
    
    return (sumaSubconjunto(c, i-1,j) || sumaSubconjunto(c, i-1,j - c[i]));
}

int main() {
    int j = 12;
    vector<int> c{6,12,6};
    int n = c.size();
    cout << sumaSubconjunto(c,n,j);

    return 0;
}