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

// Algoritmo de dijkstra desde el nodo s.
// Devuelve el vector de distancias a todos
// los nodos desde s. Un valor INF indica que
// no es posible ir de s al respectivo nodo.
vector<Costo> Dijkstra(int s) {
	vector<Costo> dist(N, INF);
	priority_queue<CostoNodo> pq;
	pq.push(CostoNodo(0, s)), dist[s] = 0;
	while (!pq.empty()) {
		Costo p = -pq.top().first;
		int u = pq.top().second; pq.pop();
		if (dist[u] < p) continue;
		for (CostoNodo arista : grafo[u]) {
			int v = arista.second;
			p = dist[u] + arista.first;
			if (p < dist[v]) dist[v] = p, 
				pq.push(CostoNodo(-p, v));
		}
	}
	return dist;
}

int main(){

}