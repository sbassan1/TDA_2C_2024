#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    //vector<int> nums = {3, 7, 1, 9, 4, 6};
    vector<int> nums = {1,2,5};

    sort(nums.begin(), nums.end()); // Segun internet esta version de sort no es estable y su complejidad es O (n log n)

    int n = nums.size();

    int costo = nums[0] + nums[1];
    int costoTotal = 0;

    for(int i = 2; i < (n) ; i++){
        costoTotal = costo + (costo + nums[i]);
        costo += nums[i]; 
    } 

    cout << costoTotal << endl;

    return 0;
}


/* 
Si ordenamos el conjunto de menor a mayor obtenemos el conjunto con el costo mas pequeño
ya que al sumar costos desde los numeros mas chicos vamos acumulando un costo total menor
comparado a sumar con numeros mas grandes. Esto se debe a que estamos acumulando el costo
basandose en la priera suma, y eligiendo elementos de menor valor minimiza esta.
 */