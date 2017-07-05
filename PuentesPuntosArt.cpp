#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Arista;

const int MAXN = 100000;
vector<int> grafo[MAXN];

int N;

// Deteccion de puentes y puntos de articulacion
// en un grafo o multigrafo bidireccional. Los puentes
// quedan guardados en un vector de aristas. Lo puntos
// de articulacion son marcados como true o false
// respectivamente en un vector de booleanos.

int tiempo;
vector<int> label, low;
vector<Arista> puentes;    // <- Resultado
vector<bool> articulacion; // <- Resultado

int PuentesArticulacion(int u, int p) {
	label[u] = low[u] = ++tiempo;

	int hijos = 0, retorno = 0;
	for (int v : grafo[u]) {
		if (v == p && !retorno++) continue;
		if (!label[v]) { ++hijos;
			PuentesArticulacion(v, u);
			if (label[u] <= low[v])
				articulacion[u] = true;
			if (label[u] <  low[v])
				puentes.push_back(Arista(u, v));
			low[u] = min(low[u], low[v]);
		}
		low[u] = min(low[u], label[v]);
	}
	return hijos;
}

void PuentesArticulacion() {
	low = vector<int>(N);
	label = vector<int>(N);
	tiempo = 0, puentes.clear();
	articulacion = vector<bool>(N);
	for (int u = 0; u < N; ++u)
		if (!label[u]) articulacion[u] =
			PuentesArticulacion(u, N) > 1;
}

int main(){

}