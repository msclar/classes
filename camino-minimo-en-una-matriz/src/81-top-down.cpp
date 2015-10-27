#include <iostream>
#include <cstdio>
using namespace std;

int matriz[128][128], calculado[128][128];
int best (int i, int j) {
	if (calculado[i][j] != -1)
		return calculado[i][j];

	// Notar que el siguiente bloque de codigo es identico en ambas implementaciones 
	if (i == 0 && j == 0)
		calculado[i][j] = matriz[0][0];
	else if (i == 0)
		calculado[i][j] = best(i, j-1) + matriz[i][j];
	else if (j == 0)
		calculado[i][j] = best(i-1, j) + matriz[i][j];
	else
		calculado[i][j] = min(best(i-1, j), best(i, j-1)) + matriz[i][j];
		
	return calculado[i][j];
}

int main () {
	freopen("81.in", "r", stdin);

	int n = 80;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matriz[i][j];
			calculado[i][j] = -1;
		}	
	}		
	
	cout << best(n-1, n-1) << endl;
	return 0;
}
