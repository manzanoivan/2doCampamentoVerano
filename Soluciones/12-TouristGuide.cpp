#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

typedef int Costo;
typedef pair<int, int> Arista;

const Costo INF = 1 << 30;

struct Grafo {

    int n; bool bi;
    vector<vector<int>> ady;
    Grafo(int N, bool B = true)
        : n(N), bi(B), ady(N) {}

    void AgregarArista(int u, int v) {
        if (bi) ady[v].push_back(u);
        ady[u].push_back(v);
    }

    // Deteccion de puentes y puntos de articulacion
    // en un grafo bidireccional. Los puentes quedan
    // guardados en un vector de aristas. Los puntos
    // de articulacion son marcados como true o
    // false en un vector de booleanos.

    int tiempo;
    vector<int> label, low;
    vector<Arista> puentes;    // <- Resultado
    vector<bool> articulacion; // <- Resultado

    int PuentesArticulacion(int u, int p) {
        label[u] = low[u] = ++tiempo;
        int hijos = 0;
        for (int v : ady[u]) {
            if (v == p) continue;
            if (!label[v]) { ++hijos;
                PuentesArticulacion(v, u);
                if (label[u] < low[v])
                    puentes.push_back(Arista(u, v));
                if (label[u] <= low[v])
                    articulacion[u] = true;
                low[u] = min(low[u], low[v]);
            }
            low[u] = min(low[u], label[v]);
        }
        return hijos;
    }

    void PuentesArticulacion() {
        low = vector<int>(n);
        label = vector<int>(n);
        tiempo = 0, puentes.clear();
        articulacion = vector<bool>(n);
        for (int u = 0; u < n; ++u)
            if (!label[u]) articulacion[u] =
                PuentesArticulacion(u, u) > 1;
    }

};

int main(){
	string cad, cad2;
	int nodos, aristas, caso = 1;
	while( 1 ){
		cin >> nodos;
		if( !nodos ) break;

		if( caso > 1 )
			cout << '\n';

		Grafo grafo( nodos );

		vector < string > vuelta;
		unordered_map< string, int > ida;

		for( int i = 0; i < nodos; i++ ){
			cin >> cad;
			ida[ cad ] = i;
			vuelta.push_back( cad );
		}

		cin >> aristas;
		while( aristas-- ){
			cin >> cad >> cad2;
			grafo.AgregarArista( ida[ cad ], ida[ cad2 ] );
		}

		grafo.PuentesArticulacion();

		set< string > conj;

		for( int i = 0; i < nodos; i++){
			if( grafo.articulacion[i] )
				conj.insert( vuelta[ i ] );
		}

		cout << "City map #"<< caso++ << ": " << conj.size() <<" camera(s) found\n";
		for( auto city: conj ){
			cout << city << '\n';
		}
	}

	return 0;
}
