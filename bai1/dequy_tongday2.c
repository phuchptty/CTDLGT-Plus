#include <stdio.h>
double tong(int n){
	double sum=0;
	if (n == 1) return 1.0/2;
	
	return tong((double)n-1)+(double)n/((double)n+1);
}

int main(void) {
	int  n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%.10lf\n", tong(n));
	}
	return 0;
}
