#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define MAXN 260005
using namespace std;

typedef int Costo;
typedef pair<int, int> Arista;

const Costo INF = 1 << 30;

typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

struct GrafoPonderado {

    int n; bool bi;
    vector<vector<CostoNodo>> ady;
    GrafoPonderado(int N, bool B = true)
        : n(N), bi(B), ady(N) {}

    void AgregarArista(int u, int v, Costo c) {
        if (bi) ady[v].push_back(CostoNodo(c, u));
        ady[u].push_back(CostoNodo(c, v));
    }

    vector<Costo> Dijkstra(int s) {
        vector<Costo> dist(n, INF);
        priority_queue<CostoNodo> pq;
        pq.push(CostoNodo(0, s)), dist[s] = 0;

        while (!pq.empty()) {
            Costo p = -pq.top().first;
            int u = pq.top().second; pq.pop();
            if (dist[u] < p) continue;

            for (CostoNodo arista : ady[u]) {
                int v = arista.second;
                p = dist[u] + arista.first;
                if (p < dist[v]) dist[v] = p,
                    pq.push(CostoNodo(-p, v));
            }
        }
        return dist;
    }
};

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, id, primerLetra, tamano;
	string ini, fin, x, y, peso;

	while( 1 ){
		
		cin >> N;
		if( !N ) break;

		id = 0;
		GrafoPonderado grafo( (52*(N+1))+2, false );
		unordered_map < string, int > mapa;

		cin >> ini >> fin;
		mapa[ ini ] = id++;
		mapa[ fin ] = id++;

		for( int i = 0; i < N; i++ ){
			cin >> x >> y >> peso;
			if( !mapa.count( x ) ) mapa[ x ] = id++;
			if( !mapa.count( y ) ) mapa[ y ] = id++;
			primerLetra = peso[0] - 'a';
			tamano = peso.size();

			for( int j = 0; j < 26; j++ ){
				if ( primerLetra == j ) continue;
				grafo.AgregarArista( (mapa[ x ] * 26) + primerLetra, (mapa[ y ] * 26) + j, tamano );
				grafo.AgregarArista( (mapa[ y ] * 26) + primerLetra, (mapa[ x ] * 26) + j, tamano );
			}
		}

		id = id*26;

		for( int i = 0; i < 26; i++ ){
			grafo.AgregarArista( id+1, (mapa[ ini ] * 26) + i , 0 );
			grafo.AgregarArista( (mapa[ fin ] * 26) + i , id, 0 );
		}

		int dist = (grafo.Dijkstra( id+1 ))[id];
		if( dist == INF ){
			cout << "impossivel\n";
		}
		else{
			cout << dist << '\n';
		}
	}

	return 0;
}
