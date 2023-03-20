#include <stdio.h>
void nhapmang(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void inmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void sort(int a[], int n){
	int i,j;
	int temp;
	for(i=0; i<n-1; i++){
		for(j=n-1;j>i;j--){
			if(a[i]<a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
}
int binSearch(int a[], int n, int x){
	int left=0, right=n-1;
	int index;
	while(left<right || left==right){
		index=(left+right)/2;
		if(x==a[index]) return index;
		if(x<a[index]) left=index+1;
		else right=index-1;
		
	}
	return -1;
}
int main(void) {
	int n;
	scanf("%d", &n);
	int a[n];
	nhapmang(a, n);
	sort(a,n);
	inmang(a,n);
	int t;
	scanf("%d", &t);
	int x;
	while(t--){
		scanf("%d", &x);
		int index= binSearch(a, n,x);
		if(index==-1){
			printf("-1\n");
		}
		else printf("%d\n", index);
	}
	return 0;
}
