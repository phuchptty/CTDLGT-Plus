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
void merge(int a[],int l, int m, int r){
    int i,j, k;
    int n1=m-l+1;
    int n2= r-m;
    int L[n1], R[n2];
     for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
       i=0; // first sub array
       j=0; // second sub array
       k=l; // new merge array
       while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        }
        else 
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // copy L to a
     while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // copy R to k
     while (j < n2) 
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r) 
    {

        int m = l + (r - l) / 2;
          printf("Divide: %d --> %d and %d --> %d\n",l,m,m+1,r);
        for (int i = l; i <= r; i++){
            printf("%d ", a[i]);
            if (i == m){
                printf(":: ");
            }
        }
        printf("\n");
        mergeSort(a, l, m);
        mergeSort(a,m+1, r);
        printf("Merge: %d --> %d and %d --> %d\n",l,m,m+1,r);
        merge(a, l, m, r);
        for (int i = l; i <= r; i++){
            printf("%d ", a[i]);
        }
        printf("\n\n");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    nhapmang(a, n);
    inmang(a,n);
    mergeSort(a,0, n-1);
    return 0;
}