#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int INF = 2e5;

int main() {

    vector<int> p{3,6,10};
    cout << "Maxima ganancia posible: " << astroTrade(p , 0, 0, 0) << endl;

    return 0;
}