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

typedef int Costo;
typedef pair<int, int> Arista;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

// Grafos con ponderacion.
// Nodos indexados de 0 a n - 1.
// GrafoPonderado(n,  true) -> Bidireccional.
// GrafoPonderado(n, false) -> Dirigido.

struct GrafoPonderado {
	int n; bool bi;
	vector<vector<CostoNodo>> ady;
	GrafoPonderado(int N, bool B = true): n(N),
		bi(B), ady(N) {}

	void AgregarArista(int u, int v, Costo c) {
		if (bi) ady[v].push_back(CostoNodo(c, u));
		ady[u].push_back(CostoNodo(c, v));
	}

	int Kruskal() {
	vector<Ponderada> todas;
	for (int u = 0; u < n; ++u)
		for (CostoNodo arista : ady[u])
			todas.push_back(Ponderada(arista.first,
						Arista(u, arista.second)));
	sort(todas.begin(), todas.end());
	// reverse(todas.begin(), todas.end());
	int ret = 0;
	UnionFind componentes(n);
	for (Ponderada arista : todas) {
		int u = arista.second.first;
		int v = arista.second.second;
		if (!componentes.SonConexos(u, v))
			componentes.Unir(u, v), 
					ret += arista.first;
	}
	return ret;
}

};

int calculaCosto( const string& A, const string& B ){
	int ret = 0, a, b;
	for( int i = 0; i < A.size(); i++ ){
		a = A[i] - '0', b = B[i]-'0';
		ret += ( abs( a - b ) <= 5 ? abs(a-b) : 10-abs(a-b) );
	}
	return ret;
}

int main(){
	int casos, N;
	cin >> casos;
	string ceros = "0000", temp;
	while( casos-- ){
		cin >> N;

		vector<string> vec;
		for( int i = 0; i < N; i++ ){
			cin >> temp;
			vec.push_back(temp);
		}

		GrafoPonderado grafo( vec.size() );

		for( int i = 0; i < vec.size(); i++ )
			for( int j = i+1; j < vec.size(); j++ )
				grafo.AgregarArista( i, j, calculaCosto( vec[i], vec[j] ) );

		int minimo = 40;
		for( int i = 0; i < vec.size(); i++ )
			minimo = min( minimo, calculaCosto( ceros, vec[i] ) );
		
		cout << grafo.Kruskal()+minimo << '\n';
	}
	return 0;
}