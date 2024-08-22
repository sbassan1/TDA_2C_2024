#include <iostream>
#include <vector>

using namespace std;

int INF = 2e5;

vector<vector<int>> mem;

bool sumaDinamica(const vector<int>& c, int i, int j) {

    if (j < 0){
        return mem[i][j] = false;
    }

    if(i == 0){
        return mem[i][j] = (j == 0);
    }

    if (mem[i][j] != INF){
        return mem[i][j];
    }
    
    return mem[i][j] = (sumaDinamica(c, i-1,j) || sumaDinamica(c, i-1,j - c[i-1]));  // Adjust index to be 0-based
}

int main() {
    int j = 12;
    vector<int> c({6,12,6});
    int n = c.size();

    mem = vector<vector<int>>(n + 1, vector<int>(j + 1, INF));  // Correct vector initialization

    cout << sumaDinamica(c,n,j) << endl;

    return 0;
}
