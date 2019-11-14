//MERIMI Mohammed 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define n 30

float puiss (float x , int m){
	if(m==0){
		return 1;
	}
	else{
		return x*puiss(x,m-1);
	}
}

int main(){
	double debut_seq, fin_seq ,debut_par,fin_par ; 
	debut_seq=clock();
	double pi_seq , sum_seq;
	double pi_par ,sum_par;
	sum_seq=0;
	sum_par=0;
	int i;
	for(i=0;i<n*400;i++){
		sum_seq=sum_seq+puiss(-1,i)/(2*i+1);
	}
	pi_seq=sum_seq*4;
	printf("le pi egal : %.9f \n",pi_seq);
	fin_seq=clock();
    printf("temps execution sequetiel=%f\n",  (double)(fin_seq-debut_seq)/CLOCKS_PER_SEC); 
    
    // parallel
    #pragma omp parallel 
    {

	#pragma omp for reduction( +: sum ) 
    {
    debut_par = clock();
    	for(i=0;i<n*400;i++){
	    sum_par=sum_par+puiss(-1,i)/(2*i+1);
	}
	pi_par=sum_par*4;
	printf("le pi egal : %.9f \n",pi_par);
    fin_par=clock();
    printf("temps execution parallel=%f\n",  (double)(fin_par-debut_par)/CLOCKS_PER_SEC); 
	}
	
    } 
    
     
}
