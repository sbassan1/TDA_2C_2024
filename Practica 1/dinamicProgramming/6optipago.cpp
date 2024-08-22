#include <iostream>
#include <vector>

using namespace std;

int INF = 2e5;

int cmpPagos( tuple<int,int> sol1, tuple<int,int> sol2){
    if (get<0>(sol1) == get<0>(sol2)) return min(get<1>(sol1) , get<1>(sol2));
    if (get<0>(sol1) < get<0>(sol2)) return get<1>(sol1); 
    if (get<0>(sol1) > get<0>(sol2)) return get<1>(sol2); 
}


int optipagoBackTracking(vector<int> billetera, int i, int costo){

    if (i == 0){
        int q = 0;
    }

    if (costo <= 0){
        return -costo; // devuelvo el costo
    }

    if (i > billetera.size()) return INF // Si el indice sobrepaso la cantidad de billetes

    return min((optipagoBackTracking(billetera, i + 1, costo), q) , 
        (optipagoBackTracking(billetera, i + 1, costo - billetera[i]), q + 1))

}

int main() {

    int costo = 14;  // Costo del producto
    vector<int> billetera{2, 3, 5, 10, 20, 20};  // Cantidad de billetes y su denominacion
    
    optipagoTopDown(billetera, costo, 0, 0, 0, excesoMinimo, menorCantidadBilletesUsados);

    cout << "Menor cantidad de billetes usados: " << menorCantidadBilletesUsados << endl;

    return 0;
}
