#include <sys/timeb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


   int  weight[1000];
   int  profit[1000];
   int  val[1000][1000];
   int  totalItems;
	int  knapCapacity;
	int  optimal[1000];

int max(int i, int j) {
    return ((i > j) ? i : j);
}

int KnapSack(int i, int j) {
    int value;
    if (val[i][j] < 0) {
        if (j < weight[i])
            value = KnapSack(i - 1, j);
        else
            value = max(KnapSack(i - 1, j), profit[i] + KnapSack(i - 1, j - weight[i]));
        val[i][j] = value;
    }
    return (val[i][j]);
}

int main() {
    int p, count = 0;
	char * filename = "LAHYANI_Zakaria.txt";
struct timeb t0, t1;    /* Timers */
double cpu_time;        /* Time */

ftime(&t0);
	FILE* file = fopen (filename, "r");
	fscanf (file, "%d" "%d", &totalItems, &knapCapacity); 
	int temp,j, i=1;
	
	for(i;i<=totalItems;++i){
		fscanf (file, "%d" "%d" "%d",&temp , &weight[i], &profit[i]);
		//printf("%d , %d\n",weight[i], profit[i] );
	}


	for (i = 0; i <= totalItems; i++)
        for (j = 0; j <= knapCapacity; j++)
            if ((i == 0) || (j == 0))
                val[i][j] = 0;
            else
                val[i][j] = -1;

	p = KnapSack(totalItems, knapCapacity);

	i = totalItems;
   j = knapCapacity;
    while (j != 0 && i != 0) {
        if (val[i][j] != val[i - 1][j]) {
            optimal[i] = 1;
            j = j - weight[i];
            i--;
        } else
            i--;
    }

	ftime(&t1);	

	printf("Items in the KnapSack are : \n\n");
  	printf(" id \t weight \t profit\n");
   printf("\n----------------------------------------\n");
   for (i = 1; i <= totalItems; i++)
        if (optimal[i])
            printf("%d \t %d \t\t  %d\n", i, weight[i], profit[i]);
   
	printf("\nTotal profit = %d\n", p);

	cpu_time = (double)(t1.time - t0.time) + (double)(t1.millitm-t0.millitm)/1000.0;
	printf("\nCPU time : %f seconds.\n", cpu_time);

    return (EXIT_SUCCESS);
}
 
