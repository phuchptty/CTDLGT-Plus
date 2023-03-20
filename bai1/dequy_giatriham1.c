#include <stdio.h>
#include <math.h>
double ham1(int n){
	if(n==1) return 1.0;
	return sqrt(n + ham1(n-1));
	
}

int main(void) {
	int  n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%.10lf\n", ham1(n));
	}
	return 0;
}
