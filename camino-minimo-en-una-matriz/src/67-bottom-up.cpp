#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	freopen("67.in", "r", stdin);
	
	int best[128][128], matriz[128][128];
	int n = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> matriz[i][j];
		}	
	}		
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			/* notar que las casillas en la primera columna solo tienen 
			 * una opcion posible. Tambien incluimos aqui el caso base */
			if (i == 0 && j == 0)
				best[0][0] = matriz[0][0];
			else if (j == 0)
				best[i][j] = best[i-1][j] + matriz[i][j];
			else
				best[i][j] = max(best[i-1][j], best[i-1][j-1]) + matriz[i][j];
		}
	}
	
	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, best[n-1][i]);
	cout << result << endl;
	return 0;
}
