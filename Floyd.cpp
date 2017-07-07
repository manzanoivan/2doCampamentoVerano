#include <iostream>
using namespace std;

int dist[MAXN][MAXN];

int main(){
	
	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] );

	return 0;
}