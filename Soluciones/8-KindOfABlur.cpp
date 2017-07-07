#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef vector< vector<double> > Matriz;
const double ERROR = 1e-9;

bool Igual(double a, double b) {
	return fabs(a - b) < ERROR;
}

void EliminaGaussiana(Matriz& m) {
	for (int i = 0; i < m.size(); ++i) {
		int fila_mayor = i;
		for (int j = i + 1; j < m.size(); ++j)
			if (fabs(m[fila_mayor][i]) <
				fabs(m[j][i])) fila_mayor = j;
		swap(m[i], m[fila_mayor]);
		if (Igual(m[i][i], 0)) continue;
		for (int j = m[i].size() - 1; j >= i; --j)
			m[i][j] /= m[i][i];
		for (int j = 0; j < m.size(); ++j) {
			if (i == j || Igual(m[j][i], 0)) continue;
			double ratio = m[j][i] / m[i][i];
			for (int k = i; k < m[j].size(); ++k)
				m[j][k] -= m[i][k] * ratio;
		}
	}
}

double imprimeDouble(double a)
{
	if(Igual(a,0)) return 0;
	return a;
}

int main() {

	int H , W, D, cont=0;
	double gradilla[17][17];

	while(1)
	{
		Matriz m;

		for(int i=0;i<17;i++)
			for(int j=0;j<17;j++)
				gradilla[i][j]=0;

		cin >> W >> H >> D;
		if(!H && !W && !D) 
			break;
		else
			if(cont++ != 0)cout << "\n";

		for(int i=0; i < H; i++)
			for(int j = 0; j < W; j++)
				cin >> gradilla[i][j];

		for(int i=0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				vector <double> grad;
				int s = 0;
				for(int k = 0; k < H; k++)
				{
					for(int l = 0; l < W ; l++)
					{
						if((abs( k-i ) + abs(l-j)) <= D )
						{
							grad.push_back( 1 );
							s++;
						}
						else
						  grad.push_back( 0 );
					}
				}
				grad.push_back( gradilla[i][j]*s );
				m.push_back( grad );
			}
		}

		EliminaGaussiana(m);
	
		int tam = H*W, ancho = W;
		for(int i=0; i< m.size() ; i++)
		{
			cout << setw(8) << right << setprecision(2)<<fixed << imprimeDouble( m[i][tam] );
			ancho--;
			if(ancho == 0){
				cout <<"\n";
				ancho = W; 
			} 
		}
	}

	return 0;
}