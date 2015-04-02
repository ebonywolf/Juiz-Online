#include <stdio.h>
#include <iostream>

//521
inline
void quickSort(int v*, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = v[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (v[i] < pivot)
                  i++;
            while (v[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = v[i];
                  v[i] = v[j];
                  v[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(v, left, j);
      if (i < right)
            quickSort(v, i, right);
}
inline
void quickSortB(int v*, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = v[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (v[i] > pivot)
                  i++;
            while (v[j] < pivot)
                  j--;
            if (i <= j) {
                  tmp = v[i];
                  v[i] = v[j];
                  v[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSortB(v, left, j);
      if (i < right)
            quickSortB(v, i, right);
}

int main()
{

	long n;
	scanf("%d", &n);
	int v[n];
	int par = 0;
	int impar = n - 1;

	int a=0;
	for ( int i = 0; i < n; i++ ) {

		scanf("%d", &a);
		//a=rand()%n;

		if ( a % 2 == 0 ) {
			v[par] = a;
			par++;

		} else {
			v[impar] = a;
			impar--;
		}
	}
	quickSort(v,0,par-1);
	quickSortB(v,impar+1,n-1);

	for (int i=0;i<n;i++){
       // printf("%i \n",v[i]);
       std::cout<< v[i] <<std::endl;
	}






	return 0;
}
