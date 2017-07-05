#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Arista;

const int MAXN = 100000;
vector<int> grafo[MAXN];

int N;

int tiempo;
vector<int> label, low;
vector<Arista> puentes;    // <- Resultado
vector<bool> articulacion; // <- Resultado

// Deteccion de componentes fuertemente conexas
// en un grafo dirigido. Las componentes quedan
// guardadas en un vector de vectores, donde
// cada vector interno contiene los nodos
// de una componente fuertemente conexa.

vector<vector<int>> scc; // <- Resultado
int top; vector<int> pila;

void FuertementeConexo(int u) {
    label[u] = low[u] = ++tiempo;

    pila[++top] = u;
    for (int v : grafo[u]) {
        if (!label[v]) FuertementeConexo(v);
        low[u] = min(low[u], low[v]);
    }
    if (label[u] == low[u]) {
        vector<int> componente;
        while (pila[top] != u) {
            componente.push_back(pila[top]);
            low[pila[top--]] = N + 1;
        }
        componente.push_back(pila[top--]);
        scc.push_back(componente);
        low[u] = N + 1;
    }
}

void FuertementeConexo() {
    low = vector<int>(N);
    label = vector<int>(N);
    tiempo = 0, scc.clear();
    top = -1, pila = vector<int>(N);
    for (int u = 0; u < N; ++u)
        if (!label[u]) FuertementeConexo(u);
}

int main(){
    
}
