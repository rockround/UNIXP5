#include <gsl/gsl_rng.h>
#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>

int initTool();
void finalizeTool();
double getRDM();

gsl_rng_type *_gsl_rng_type;
gsl_rng *_gsl_rng;

int initTool(){
	_gsl_rng = gsl_rng_alloc(gsl_rng_mt19937);

	if(_gsl_rng == NULL)
		return 1;
	else
		return 0;
}

void finalizeTool(){
	gsl_rng_free(_gsl_rng);
	return;
}

double getRDM(){
	return(gsl_rng_uniform(_gsl_rng));
}
int main(int argc,char **argv ){
 int i;
 int percent = 0;
 int trials = 0;
 int option = 0;
 int verbose =0;
 while((option=getopt(argc,argv,"v::p:"))!=-1){
  switch(option){
   case 'v':
    verbose =1;
    break;
   case 'p':
    percent = atoi(optarg);
    break;
   default:
     printf("Invalid Syntax%d:\n",atoi(optarg));
     return 1;
    }
  }
  if(optind<argc){
  // while(optind<argc)
  //  printf("%s ",argv[optind++]);
  // printf("\n");
     trials = atoi(argv[optind]);
   }else{
    return 1;
   }
 const int NUM_ITERS=10;
 printf("Percent:%d\t,Trials:%d\t,isVerbose:%d\n",percent,trials,verbose);
 assert(initTool()==0);
 
 for(i=0;i<NUM_ITERS;i++)
  printf("Random Number = %f\n",getRDM());
 
 finalizeTool();
 
 return 0;

}
