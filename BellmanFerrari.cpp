#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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


// Algoritmo de Bellman-Ford optimizado, desde
// el nodo s. Devuelve un booleano indicando si
// existe un ciclo negativo en un digrafo.
// Obtiene el vector de distancias a todos.
vector<Costo> dist; // <- Resultado
bool BellmanFord(int s) {
	queue<int> q;
	vector<bool> en_cola(N);
	vector<int> procesado(N);
	dist = vector<Costo>(N, INF);
	q.push(s), dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop(), en_cola[u] = false;
		if (++procesado[u] == N) return true;
		for (CostoNodo arista : grafo[u]) {
			int v = arista.second;
			Costo p = arista.first;
			if (dist[u] + p < dist[v]) {
				if (!en_cola[v]) q.push(v);
				dist[v] = dist[u] + p;
				en_cola[v] = true;
			}
		}
	}
	return false;
}

int main(){

}