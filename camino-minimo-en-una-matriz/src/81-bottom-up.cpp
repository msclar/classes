#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	freopen("81.in", "r", stdin);
	freopen("81.out", "w", stderr);
	
	int best[128][128], matriz[128][128];
	int n = 80;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matriz[i][j];
		}	
	}		
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			/* notar que las casillas en la primera columna solo tienen 
			 * una opcion posible. Tambien incluimos aqui el caso base */
			if (i == 0 && j == 0)
				best[0][0] = matriz[0][0];
			else if (i == 0)
				best[i][j] = best[i][j-1] + matriz[i][j];
			else if (j == 0)
				best[i][j] = best[i-1][j] + matriz[i][j];
			else
				best[i][j] = min(best[i-1][j], best[i][j-1]) + matriz[i][j];
		}
	}
	
	cout << best[n-1][n-1] << endl;
	return 0;
}
