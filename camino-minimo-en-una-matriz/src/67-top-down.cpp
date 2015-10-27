#include <iostream>
#include <cstdio>
using namespace std;

int matriz[128][128], calculado[128][128];

int best (int i, int j) {
	if (calculado[i][j] != -1)
		return calculado[i][j];

	int result = 0;
	// se puede escribir mas lindo, pero lo dejamos igual que el bottom-up 
	// por motivos pedagogicos (notar son casi iguales y funciona!)
	if (i == 0 && j == 0)
		result = matriz[0][0];
	else if (j == 0)
		result = best(i-1, j) + matriz[i][j];
	else
		result = max(best(i-1, j), best(i-1, j-1)) + matriz[i][j];
		
	calculado[i][j] = result;
	return result;
}

int main () {
	freopen("67.in", "r", stdin);
	
	int n = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> matriz[i][j];
			calculado[i][j] = -1;
		}	
	}		
	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, best(n-1, i));
	cout << result << endl;
	return 0;
}
