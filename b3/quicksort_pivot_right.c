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

void inmang_fl(int a[], int first, int last){
    for (int i = first; i <= last; i++){
            printf("%d ", a[i]);
        }
    printf("\n");
}

void quicksort(int a[], int first, int last){
    int i, j, pivot, temp;

    if(first<last){
        
        printf("Partitioning: left=%d, right=%d\n", first, last);
        inmang_fl(a,first,last);
        
        pivot=last;

        i=first;

        j=last;

        while(i<j){

            while(a[i]>a[pivot]&&i<last)

                i++;

            while(a[j]<=a[pivot])

                j--;

            if(i<j){

                temp=a[i];

                a[i]=a[j];

                a[j]=temp;
                inmang_fl(a,first,last);
            }

    }

    temp=a[pivot];

    a[pivot]=a[i];

    a[i]=temp;
    
    inmang_fl(a,first,last);
    printf("\n");

    quicksort(a,first,i-1);

    quicksort(a,i+1,last);

    }

}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    nhapmang(a, n);
    inmang(a,n);
    printf("\n");

    quicksort(a,0,n-1);

    inmang(a,n);

    return 0;
}