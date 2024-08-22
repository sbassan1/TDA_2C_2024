#include <iostream>
#include <vector>

using namespace std;

int INF = 2e5;

vector<int> mem;
void optipagoTopDown(vector<int>& billetera, int costo, int i, int excesoActual, int cantBilletesUsados, int &excesoMinimo, int &menorCantidadBilletesUsados) {

    if (costo <= 0) {  // Si hemos pagado el costo o lo hemos excedido
        excesoActual = -costo;  // El exceso real
        if (excesoActual < excesoMinimo || 
            (excesoActual == excesoMinimo && cantBilletesUsados < menorCantidadBilletesUsados)) {
            excesoMinimo = excesoActual;
            menorCantidadBilletesUsados = cantBilletesUsados;
        }
        return;
    }

    if (i >= billetera.size()) {  // Si hemos revisado todos los billetes
        return;
    }

    // Tomamos el billete actual
    optipagoTopDown(billetera, costo - billetera[i], i + 1, excesoActual + billetera[i], cantBilletesUsados + 1, excesoMinimo, menorCantidadBilletesUsados);

    // No tomamos el billete actual
    optipagoTopDown(billetera, costo, i + 1, excesoActual, cantBilletesUsados, excesoMinimo, menorCantidadBilletesUsados);
}

int main() {

    int costo = 14;  // Costo del producto
    vector<int> billetera{2, 3, 5, 10, 20, 20};  // Cantidad de billetes y su denominacion
    int menorCantidadBilletesUsados = INF;
    int excesoMinimo = INF;
    
    optipagoTopDown(billetera, costo, 0, 0, 0, excesoMinimo, menorCantidadBilletesUsados);

    cout << "Menor cantidad de billetes usados: " << menorCantidadBilletesUsados << endl;

    return 0;
}
