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

void quicksort(int a[], int first, int last){
	int i, j, pivot, temp;

	if(first<last){
        
        // Chon pivot la phan tu dau
		pivot=first;

		i=first;

		j=last;

		while(i<j){
            
            // net lon hon pivot. nguoc voi tang
			while(a[i] >= a[pivot] && i<last)
				i++;

            // net nho hon pivot
			while(a[j] < a[pivot])
				j--;

            // dao vi tri
			if(i<j) {
				temp=a[i];

				a[i]=a[j];

				a[j]=temp;
			}
	}

    // gop 2 mang
	temp=a[pivot];

	a[pivot]=a[j];

	a[j]=temp;

    // tiep tuc search 2 phia
	quicksort(a,first,j-1);

	quicksort(a,j+1,last);

	}

}

int main(void) {
	int n;
	scanf("%d", &n);

	int a[n];
	nhapmang(a, n);

	quicksort(a,0,n-1);

	inmang(a,n);
	return 0;
}
