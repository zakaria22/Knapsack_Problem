#include <stdio.h>
 
int main()
{
   int m=7,n=3, c, d, z[7][3], x[7][3], res[3];
   int first[7][3] = {{0, 0, 0},{3, 4, 2}, {4, 6, 4}, {4, 7, 6},{4,8,7}, {4,8,8}, {4,8,9}};

 
	//initialisation	
	for (c = 0; c < m; c++) {
		z[c][0] = first[c][0];
		x[c][0] = c;
	}

	int k=0;int test,temp,lol;
	
	//traitemant
	for(d=1;d<n;++d){
		for (c = 0; c < m; c++) {
			k=0;test= 0;
			while(k<=c){
				
				temp = first[k][d]+z[c-k][d-1];
				if(temp>=test){
					test = temp;
					lol = k;
					
				}
				k++;
			}
			z[c][d] = test;  
			x[c][d] = lol;
		}  
	}
	
	//resultat
	printf("-------------------------------------------------------------------------------------------------\n");
  	printf("  z1(alpha) \t| x1(alpha)\t| z2(alpha) \t|  x2(alpha)\t|   z3(alpha) \t|  x3(alpha)\t|\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	
	for (c = 0; c < m; c++) {
		for(d=0;d<n;++d){
			printf("      %d \t|\t %d \t|" , z[c][d] , x[c][d]);	
		}  
		printf("\n");
	}
	printf("-------------------------------------------------------------------------------------------------\n\n");


	m = m-1;
	int kk=0;

	for(c=0;c<d;++c){
		res[kk] = 	x[m][d-c-1];		
		m=m-x[m][d-c-1];
		kk++;
	}
	printf(" solution [ ");
	for(kk=2;kk>=0;--kk){
			printf(" %d ,",res[kk]);	
	}
	printf(" ] \n");
	printf(" optimal solution = %d \n",z[6][2]  );

   return 0;
}
