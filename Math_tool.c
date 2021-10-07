#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
int findCommon(int bn1[], int bn2[], int bn3[],int bn4[],int bn5[], int n1, int n2, int n3, int n4, int n5 ) 
{ 
	// Initialize starting indexes for ar1[], ar2[] and ar3[] 
	int i = 1, j = 1, k = 1,l=1,m=1 , common_box;

	// Iterate through three arrays while all arrays have elements 
	while (i < n1 && j < n2 && k < n3 && l < n4 && m < n5 ) 
	{ 
		// If x = y and y = z, print any of them and move ahead 
		// in all arrays 
		if (bn1[i] == bn2[j] && bn2[j] == bn3[k] && bn3[k]==bn4[l] && bn4[l]==bn5[m]) 
		{ 
		common_box= bn1[i];
	//	printf ("%d \n ",common_box); 
		i++; j++; k++;l++;m++; } 
		

		// x < y 
		else if (bn1[i] < bn2[j]) 
			i++; 
		// y < z 
		else if (bn2[j] < bn3[k]) 
			j++; 

		// We reach here when x > y and z < y, i.e., z is smallest 
		else if (bn3[k] < bn4[l])
			k++; 
		else if (bn4[l]<bn5[m])
			l++;
		else 
		m++;
	} 
	return (common_box);
}
void   sort(int arr[],int n)
{
    int  i, j, tmp;
	 for(i=1; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[j] <arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
  /*  for(i=1; i<n; i++)
    {
        printf("\n%d  ", arr[i]);
    }*/
}
void eliminate(int arr_1[], int arr1[])
{
	int i,j;
	for (i = 1,j=1; i < 12; i++) {
        if (arr_1[i] != 0) {
            arr1[j++] = arr_1[i]; // if true, populate new array with value
		}
    }
  /* for (i = 1; i < j; i++) {
          printf(" \n %d,", arr1[i]);
    }*/
}
/*double reverse_int (int x, int y , double bucket[][9][5], int k1,int k2, double pr[])
{	double mac[5],aoa[9];
    int i,j,c,d,k,v,w,t,h;
   double x1,x2,y1,y2,f11,f21,f22,f12,f_11,f_12,f_21,f_22,o,p,m,m_,n,n_,a1,b1,c1,d1,a2,b2,c2,d2,A,B,C,x_1,y_1,x_2,y_2,xx,yy;
   	for (i=1;i<6;i++)
	{
		mac[i]=i*0.1+0.1;
	}
	for (j=1;j<10;j++)
	{
		aoa[j]=-4+2*(j-1);
	}
			     		    x2=mac[x+1];
						  	x1=mac[x];
						  	y1=aoa[y];
						  	y2=aoa[y+1];
						  	f21= bucket[x+1][y][k1];
						  	f11=bucket[x][y][k1];
						  	f22=bucket[x+1][y+1][k1];
						  	f12=bucket[x][y+1][k1];
							f_21= bucket[x+1][y][k2];
						  	f_11=bucket[x][y][k2];
						  	f_22=bucket[x+1][y+1][k2];
						  	f_12=bucket[x][y+1][k2];
						  	
			   /*to do the operation*/
			  /* printf("\n%lf",bucket[x+1][y][k1]);
			   printf ("\n%d",x);
			   printf ("\n%d",y);
			   printf ("\n%d",k1);
			    printf ("\n%d",k2);
			   printf ("\n%lf",pr[k1]);
			   printf ("\n%lf",pr[k2]);
			   printf ("\n%lf",x2);
			   printf ("\n%lf",x1);
			    printf ("\n%lf",y1);
			     printf ("\n%lf",y2);
			      printf ("\n%lf",f11);
			      printf ("\n%lf",f12);
			      printf ("\n%lf",f21);
			      printf ("\n%lf",f22);
			       printf ("\n%lf",f_11);
			      printf ("\n%lf",f_12);
			      printf ("\n%lf",f_21);
			      printf ("\n%lf",f_22);
			      
				   o= y2-y1;
				   p=x2-x1;
				   m=f22-f12;
				   m_=f_22-f_12;
				   n=f21-f11;
				   n_=f_21-f_11;  
				   a1=(n*y2-m*y1);
				   b1=(m-n);
				   c1=(x2*f12-x2*f11+x1*f21-x1*f22);
				   d1= (pr[k1]*o*p-x1*f22*y1+x2*f12*y1+x1*y2*f21-x2*y2*f11);
				   a2=(n_*y2-m_*y1);
				   b2=(m_-n_);
				   c2=(x2*f_12-x2*f_11+x1*f_21-x1*f_22);
				   d2= (pr[k2]*o*p-x1*f_22*y1+x2*f_12*y1+x1*y2*f_21-x2*y2*f_11);
				   A=(a2*b1-a1*b2);
				   printf ("\n%lf",A);
				   B=(a2*c1-c2*a1+b2*d1-d2*b1);
				   C=(c2*d1-d2*c1);
				    if (A>0)
				     {
				     	printf ("\n there are more than one values , either one or both of the functions are non linear");
				     	x_1= (-B/2*A)+ sqrt(B*B-4*A*C)/2*A;
				     	x_2= (-B/2*A)- sqrt(B*B-4*A*C)/2*A;
				     	y_1= (d1-a1*x_1)/(b1*x_1+c1);
				     	y_2= (d1-a1*x_2)/(b1*x_2+c1);
				        if (mac[x+1]>=x_1 && mac[x]<=x_1)
				        {
				        	printf ("\n the value of x and y obtained are \n x=%lf \n y=%lf",x_1,y_1);
				        	return (x_1,y_1);
						}
						else if (mac[x+1]>=x_2 && mac[x]<= x_2)
						{
							printf ("\n the value of x and y obtained are \n x=%lf \n y=%lf",x_2,y_2);
							return (x_2,y_2);
						}
					 }
					else if (A==0)
					 {
					 	printf("\n the functions are linear");
					 	xx = -C/B;
					 	yy=(d1-a1*xx)/(b1*xx+c1);
					 	printf("\n the value of x and y are \n  x=%lf  \n y=%lf ",xx,yy);
					 	return(xx,yy);
				}
				else 
				{
					printf("no-solution");
				}
			     	
			}*/

int main()
{
int i = 1,j=1,k=1,l=1,m=1,x,y,k1,k2;
double del_p[5];
double p_min[5];
double p_max[5];
int line[166][12]={0};
double bucket [10][10][10]={0};
int   slt_min[10][10][10]={0};
int   slt_max[10][10][10]={0};
double pr[5];
int slt[5];
char check ;
int buck [10][10][10]={0};
int bn[5][12]={0};
int n;
int bn_1[12]={0};
int bn_2[12]={0};
int bn_3[12]={0};
int bn_4[12]={0};
int bn_5[12]={0};
int bn1[12]={0};
int bn2[12]={0};
int bn3[12]={0};
int bn4[12]={0};
int bn5[12]={0};
int cb={0};
float mac[5]={0};
float aoa[9]={0};
double x1=0,x2=0,y1=0,y2=0,f11=0,f21=0,f22=0,f12=0,f_11=0,f_12=0,f_21=0,f_22=0,o=0,p=0,m_1=0,m_2=0,n_1=0,n_2=0,a1=0,b1=0,c1=0,d1=0,a2=0,b2=0,c2=0,d2=0;
double A=0,B=0,C=0,x_1=0,y_1=0,x_2=0,y_2=0,xx=0,yy=0,ch=0;
	//bucket operation  
    FILE *fp1 = fopen("mac0.2.txt", "r");
	if (fp1==NULL)
	{
		printf("could not open file ");
		return(0);
	}
	 for(i=1;i<6;i++)
	 	{
	 		for (j=1;j<10;j++)
	 		 {
	 		 	for (k=1;k<6;k++)
	 		 	{ 
	 		 	
	 		 			fscanf(fp1,"%lf",&bucket[i][j][k]);
	 		 
     } 
	 }
	 }
	fclose(fp1);
	 for(i=1;i<6;i++)
	 	{
	 		for (j=1;j<10;j++)
	 		 {
	 		 	for (k=1;k<6;k++)
	 		 	{ 
	 		 	
	 		 			printf("\n %lf",bucket[i][j][k]);
	 		 
     } 
	 }
	 }
printf("\n%lf",bucket[2][5][1]);
printf("\n%lf",bucket[2][6][1]);
printf("\n%lf",bucket[3][6][1]);
printf("\n%lf",bucket[3][5][1]);
printf("\n%lf",bucket[2][5][2]);
printf("\n%lf",bucket[2][6][2]);
printf("\n%lf",bucket[3][6][2]);
printf("%\n %lf",bucket[3][5][2]);
	
	// to find the min and max of  each bucket 
	double buck_max[5][9][5]= {0};
	double buck_min[5][9][5]={0};
	double val[4]={0};
	for (i=1;i<5;i++)
	{
		for (j=1;j<9;j++)
		{
			for (k=1;k<6;k++)
			{
				if (k==1)
				{
					val[1]=bucket[i][j][k];
					val[2]=bucket[i+1][j][k];
					val[3]=bucket[i+1][j+1][k];
					val[4]=bucket[i][j+1][k];
					buck_max[i][j][k]=val[1];
					buck_min[i][j][k]=val[1];
					for (l=1;l<5;l++)
					{
					if (buck_max[i][j][k]<val[l])
					{
						buck_max[i][j][k]=val[l];
					}
					if (buck_min[i][j][k]>val[l])
					{
						buck_min[i][j][k]=val[l];
					}
				}
					
				}
					else if (k==2)
				{
					val[1]=bucket[i][j][k];
					val[2]=bucket[i+1][j][k];
					val[3]=bucket[i+1][j+1][k];
					val[4]=bucket[i][j+1][k];
						buck_max[i][j][k]=val[1];
					buck_min[i][j][k]=val[1];
					for (l=1;l<5;l++)
					{
					if (buck_max[i][j][k]<val[l])
					{
						buck_max[i][j][k]=val[l];
					}
					if (buck_min[i][j][k]>val[l])
					{
						buck_min[i][j][k]=val[l];
					}
				}
					
				}
					else if (k==3)
				{
					val[1]=bucket[i][j][k];
					val[2]=bucket[i+1][j][k];
					val[3]=bucket[i+1][j+1][k];
					val[4]=bucket[i][j+1][k];
						buck_max[i][j][k]=val[1];
					buck_min[i][j][k]=val[1];
					for (l=1;l<5;l++)
					{
					if (buck_max[i][j][k]<val[l])
					{
						buck_max[i][j][k]=val[l];
					}
					if (buck_min[i][j][k]>val[l])
					{
						buck_min[i][j][k]=val[l];
					}
				}
					
				}
					else if (k==4)
				{
					val[1]=bucket[i][j][k];
					val[2]=bucket[i+1][j][k];
					val[3]=bucket[i+1][j+1][k];
					val[4]=bucket[i][j+1][k];
						buck_max[i][j][k]=val[1];
					buck_min[i][j][k]=val[1];
					for (l=1;l<5;l++)
					{
					if (buck_max[i][j][k]<val[l])
					{
						buck_max[i][j][k]=val[l];
					}
					if (buck_min[i][j][k]>val[l])
					{
						buck_min[i][j][k]=val[l];
					}
				}
					
				}
					else 
				{
					val[1]=bucket[i][j][k];
					val[2]=bucket[i+1][j][k];
					val[3]=bucket[i+1][j+1][k];
					val[4]=bucket[i][j+1][k];
						buck_max[i][j][k]=val[1];
					buck_min[i][j][k]=val[1];
					for (l=1;l<5;l++)
					{
					if (buck_max[i][j][k]<val[l])
					{
						buck_max[i][j][k]=val[l];
					}
     				if (buck_min[i][j][k]>val[l])
					{
						buck_min[i][j][k]=val[l];
					}
				}
					
				}
			}
		}
	}
	printf ("\n the maximum bucket value = %lf", buck_max[2][5][1]);
//	printf ("\n the minimum bucket value = %lf", buck_min[2][5][4]);
	
	
/*for(i=1; i < 6; i++)
{
    for(j=1; j <10; j++)
     {
     	for (k=1;k<6;k++)
     	{
        printf("%lf ", bucket[i][j][k]);
        printf("\n");
        }
     }
 }*/
 //common box to find common bucket
  del_p[1]=0.018155456;    p_min[1]=0.664249152;     p_max[1]=1.245223738;
 del_p[2]= 0.029675796;    p_min[2]=0.219145352;  p_max[2]=1.168770791;
 del_p[3]=0.021433705;    p_min[3]=0.578727376;  p_max[3]=1.264605925;
 del_p[4]=0.003932519;    p_min[4]=0.871898036;  p_max[4]=0.997738657;
 del_p[5]=0.004266813;   p_min[5]=0.886246493;  p_max[5]=1.022784493;
 for (i=1;i<5;i++)
 {
 	for (j=1;j<9;j++)
 	{
	 for (k=1;k<6;k++)
	 {
 	slt_max[i][j][k]=ceil((buck_max[i][j][k]-p_min[k])/del_p[k]);
 	slt_min[i][j][k]=ceil((buck_min[i][j][k]-p_min[k])/del_p[k]);
 	
 }
}
}
printf ("\n the min slt value for press %d",slt_min[3][1][2]);
printf ("\n the max slt  value for press %d",slt_max[3][1][2]);
printf ("\n the bucket max value %lf ", buck_max[3][1][2]);
pr[1]= 0.996851642;
pr[2]=0.84998265;
pr[3]=1.064820439;
pr[4]=0.962646024;
pr[5]=0.997858782;

	 	for (k=1;k<6;k++)
	 	{
	 		slt[k]=ceil((pr[k]-p_min[k])/del_p[k]);
	     	}
	 		
	 //	printf ("the value of slot %d ",slt[1]);
	 	//	printf ("\n%d",slt_max[4][8][5]);
	for (k=1;k<6;k++)
	{
		for (j=1;j<9;j++)
	
		{
				for (i=1;i<5;i++)
			{
				if (j%2==0)
				{
					buck[i][j][k]= 4*j-i+1;
				//	printf("\n%d",buck[i][j][k]);
				}
				else 
				{
					buck[i][j][k]=(4*(j-1))+i;
				//	printf("\n%d",buck[i][j][k]);
				}
			}
		}
		  }	
		    
for (k=1;k<6;k++)
{
 m=1;	l=1;
for (i=1;i<5;i++)
 {
 	for (j=1;j<9;j++)
	 {
	 	if (slt[k]==32 && slt_max[i][j][k]>=slt[k] && slt[k]>=slt_min[i][j][k])
	 	{
	 		
	 		//	printf ("\n the pressure-%d lies in box %d  ",k,buck[i][j][k]);

	 		bn[k][m]=buck[i][j][k];
	 	//	printf ("\n common boxes %d =%d",k,bn[k][m]);
	 	if (k==1)
	 	{
	 		bn_1[l]=bn[k][m];
	 		//	printf (" \n %dth box for pressure %d = %d",l,k,bn1[l]);
	 		l++;
	 	
		 }
		 else 	if (k==2)
	 	{
	 		bn_2[l]=bn[k][m];
	 		//printf (" \n %dth box for pressure %d = %d",l,k,bn2[l]);
	 		l++;
		 }
		 else 	if (k==3)
	 	{
	 		bn_3[l]=bn[k][m];
	 		//printf (" \n %dth box for pressure %d = %d",l,k,bn3[l]);
	 		l++;
		 }
		 else 	if (k==4)
	 	{
	 		bn_4[l]=bn[k][m];
	 		//printf (" \n %dth box for pressure %d = %d",l,k,bn4[l]);
	 		l++;
		 }
		 else  
	 	{
	 		bn_5[l]=bn[k][m];
	 	//	printf (" \n %dth box for pressure %d = %d",l,k,bn5[l]);
	 		l++;
		 }
	 		m++;
				 		 }
	  else if (slt_max[i][j][k]>slt[k] && slt[k]>=slt_min[i][j][k])
	 		{
				printf ("\n the pressure-%d lies in box %d  ",k,buck[i][j][k]);
	 		bn[k][m]=buck[i][j][k];
	 	//	printf ("\n common boxes %d =%d",k,bn[k][m]);
	 	if (k==1)
	 	{
	 		bn_1[l]=bn[k][m];
	 		//printf (" \n %dth box for pressure %d = %d",l,k,bn1[l]);
	 		l++;
		 }
		 else 	if (k==2)
	 	{
	 		bn_2[l]=bn[k][m];
	 	//	printf (" \n %dth box for pressure %d = %d",l,k,bn2[l]);
	 		l++;
		 }
		 else 	if (k==3)
	 	{
	 		bn_3[l]=bn[k][m];
	 	//	printf (" \n %dth box for pressure %d = %d",l,k,bn3[l]);
	 		l++;
		 }
		 else 	if (k==4)
	 	{
	 		bn_4[l]=bn[k][m];
	 	//	printf (" \n %dth box for pressure %d = %d",l,k,bn4[l]);
	 		l++;
		 }
		 else  
	 	{
	 		bn_5[l]=bn[k][m];
	 	//	printf (" \n %dth box for pressure %d = %d",l,k,bn5[l]);
	 		l++;
		 }
	 		m++;
			 }
		 }
		 
	 }
 }
/* for (l=1;l<12;l++)
 {
 	printf ("\n%d",bn1[l]);
 }
  for (l=1;l<12;l++)
 {
 	printf ("\n%d",bn2[l]);
 }
  for (l=1;l<12;l++)
 {
 	printf ("\n%d",bn3[l]);
 }
  for (l=1;l<12;l++)
 {
 	printf ("\n%d",bn4[l]);
 }
  for (l=1;l<12;l++)
 {
 	printf ("\n%d",bn5[l]);
 }*/
 //making new array without zero.
     
    int n1 = sizeof(bn_1)/sizeof(bn_1[0]);
	int n2 = sizeof(bn_2)/sizeof(bn_2[0]); 
	int n3 = sizeof(bn_3)/sizeof(bn_3[0]);
	int n4 = sizeof(bn_4)/sizeof(bn_4[0]);
	int n5 = sizeof(bn_5)/sizeof(bn_5[0]);
	//sorting array 
	sort (bn_1,n1);
	sort (bn_2,n2);
	sort (bn_3,n3);
	sort (bn_4,n4);
	sort (bn_5,n5);
    eliminate (bn_1,bn1);
    eliminate (bn_2,bn2);
    eliminate (bn_3,bn3);
    eliminate (bn_4,bn4);
    eliminate (bn_5,bn5);
    cb=findCommon(bn1,bn2,bn3,bn4,bn5,n1,n2,n3,n4,n5);
    printf ("\n j-th value =%d",cb);
    y= (cb/4)+1;
    printf("\n %d",y);
    if (y%2==0)
    {
    	 x = (4*y)+1-cb;
    	 printf ("\n i th value=%d ",x);
	}
	   else 
	   {
	   	x = cb-(4*(y-1));
	   	printf ("\n i th value=%d ",x);
	   }
	   	for (i=1;i<6;i++)
	{
		mac[i]=i*0.1+0.1;
	}
	for (j=1;j<10;j++)
	{
		aoa[j]=-4+2*(j-1);
	}
	   printf ("\n enter the value of k1");
	   scanf("%d",&k1);
	   printf ("\n enter the value of k2");
	   scanf("%d",&k2);
	   
	  // reverse_int (x,y,bucket,1,2,pr);
	                        x2=mac[x+1];
						  	x1=mac[x];
						  	y1=aoa[y];
						  	y2=aoa[y+1];
						  	f21= bucket[x+1][y][k1];
						  	f11=bucket[x][y][k1];
						  	f22=bucket[x+1][y+1][k1];
						  	f12=bucket[x][y+1][k1];
							f_21= bucket[x+1][y][k2];
						  	f_11=bucket[x][y][k2];
						  	f_22=bucket[x+1][y+1][k2];
						  	f_12=bucket[x][y+1][k2];
						  	
			   /*to do the operation*/
			   printf("\n%lf",bucket[x+1][y][k1]);
			   printf ("\n%d",x);
			   printf ("\n%d",y);
			   printf ("\n%d",k1);
			    printf ("\n%d",k2);
			   printf ("\n%lf",pr[k1]);
			   printf ("\n%lf",pr[k2]);
			   printf ("\n%lf",x2);
			   printf ("\n%lf",x1);
			    printf ("\n%lf",y1);
			     printf ("\n%lf",y2);
			      printf ("\n%lf",f11);
			      printf ("\n%lf",f12);
			      printf ("\n%lf",f21);
			      printf ("\n%lf",f22);
			       printf ("\n%lf",f_11);
			      printf ("\n%lf",f_12);
			      printf ("\n%lf",f_21);
			      printf ("\n%lf",f_22);
			      
				   o= y2-y1;
				   printf("\n O=%lf",o);
				   p=x2-x1;
				      printf("\n p=%lf",p);
				   m_1=f22-f12;
				        printf("\n m_1=%lf",m_1);
				   m_2=f_22-f_12;
				    printf("\n m_2=%lf",m_2);
				   n_1=f21-f11;
				    printf("\n n_1=%lf",n_1);
				   n_2=f_21-f_11;  
				   printf("\n n_2=%lf",n_2);
				   a1=(n_1*y2-m_1*y1);
				   printf("\n a1=%lf",a1);
				   b1=(m_1-n_1);
				     printf("\n b1=%lf",b1);
				   c1=(x2*f12-x2*f11+x1*f21-x1*f22);
				     printf("\n c1=%lf",c1);
				   d1= (pr[k1]*o*p-x1*f22*y1+x2*f12*y1+x1*y2*f21-x2*y2*f11);
				     printf("\n d1=%lf",d1);
				   a2=(n_2*y2-m_2*y1);
				    printf("\n a2=%lf",a2);
				   b2=(m_2-n_2);
				     printf("\n b2=%lf",b2);
				   c2=(x2*f_12-x2*f_11+x1*f_21-x1*f_22);
				   printf("\n c2=%lf",c2);
				   d2= (pr[k2]*o*p-x1*f_22*y1+x2*f_12*y1+x1*y2*f_21-x2*y2*f_11);
				   printf("\n d2=%lf",d2);
				   A=(a2*b1-a1*b2);
				   printf ("\n A=%lf",A);
				   B=(a2*c1-c2*a1+b2*d1-d2*b1);
			       printf ("\n B=%lf",B);   
				   C=(c2*d1-d2*c1);
				    printf ("\n C=%lf",C);
				    ch= sqrt (B*B-4*A*C);
				    printf ("\n ch=%lf",ch);
				    if (A!=0)
				     {
				     	printf ("\n there are more than one values , either one or both of the functions are non linear");
				    printf ("\n A=%lf",A);
				     printf ("\n B=%lf",B);
				     printf ("\n C=%lf",C);
				     printf ("\n ch=%lf",ch);
				     	x_1=((-B)+ch)/(2*A);
				     	printf ("\n x_1=%lf", x_1);
				     	x_2= (-B-ch)/(2*A);
				     	printf ("\n x_2=%lf", x_2); 
				     	y_1= (d1-a1*x_1)/(b1*x_1+c1);
				     	printf ("\n y_1=%lf", y_1);
				     	y_2= (d1-a1*x_2)/(b1*x_2+c1);
				     	printf ("\n y_2=%lf", y_2);
				        if (mac[x+1]>=x_1 && mac[x]<=x_1)
				        {
				        	printf ("\n the value of x and y obtained are \n x=%lf \n y=%lf",x_1,y_1);
				        	return (x_1,y_1);
						}
						else if (mac[x+1]>=x_2 && mac[x]<= x_2)
						{
							printf ("\n the value of x and y obtained are \n x=%lf \n y=%lf",x_2,y_2);
							return (x_2,y_2);
						}
					 }
					else if (A==0)
					 {
					 	printf("\n the functions are linear");
					 	xx = -C/B;
					 	yy=(d1-a1*xx)/(b1*xx+c1);
					 	printf("\n the value of x and y are \n  x=%lf  \n y=%lf ",xx,yy);
					 	return(xx,yy);
				}
				else 
				{
					printf("no-solution");
				}
			     	
		
}



