#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Conjuntos disjuntos con Union-Find.
struct UnionFind {
	int n; vector<int> padre, tam;
	UnionFind(int N) : n(N), tam(N, 1), padre(N) {
		while (--N) padre[N] = N;
	}
	int Raiz(int u) {
		if (padre[u] == u) return u;
		return padre[u] = Raiz(padre[u]);
	}
	bool SonConexos(int u, int v) {
		return Raiz(u) == Raiz(v);
	} 
	void Unir(int u, int v) {
		int Ru = Raiz(u); int Rv = Raiz(v);
		if (Ru == Rv) return;
		--n, padre[Ru] = Rv;
		tam[Rv] += tam[Ru];
	}
	int Tamano(int u) {
		return tam[Raiz(u)];
	}
};

const int MAXN = 100000;

typedef int Costo;
typedef pair<int, int> Arista;
const Costo INF = 1 << 30;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

int N = MAXN;//número de nodos

vector<vector<CostoNodo>> grafo;

void AgregarArista(int u, int v, Costo c) {
	grafo[u].push_back(CostoNodo(c, v));
}

// Obtiene el arbol de expansion minima de un
// grafo bidireccional. Para obtener el arbol
// de expansion maxima descomentar el reverse.
// En caso de tener varias componentes conexas,
// obtiene el bosque de expansion minima.
vector<Ponderada> Kruskal() {
	vector<Ponderada> todas;
	for (int u = 0; u < N; ++u)
		for (CostoNodo arista : grafo[u])
			todas.push_back(Ponderada(arista.first,
						Arista(u, arista.second)));
	sort(todas.begin(), todas.end());
	// reverse(todas.begin(), todas.end());
	vector<Ponderada> mst;
	UnionFind componentes(N);
	for (Ponderada arista : todas) {
		int u = arista.second.first;
		int v = arista.second.second;
		if (!componentes.SonConexos(u, v))
			componentes.Unir(u, v), 
					mst.push_back(arista);
	}
	return mst;
}

int main(){
	
}