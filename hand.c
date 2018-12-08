#include <gsl/gsl_rng.h>
#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>

int initTool();
void finalizeTool();
int getRDM();

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

int getRDM(){
	return(100*gsl_rng_uniform(_gsl_rng));
}
int main(int argc,char **argv ){
 int i;
 int option=0;
 int percent = 0;
 while((option=getopt(argc,argv,"p:"))!=-1){
  switch(option){
   case 'p':
    percent = atoi(optarg);
    break;
   default:
     printf("Invalid Syntax%d:\n",atoi(optarg));
     return 1;
    }
  }
 assert(initTool()==0);
 if(getRDM()<=percent)
  printf("Success");
 else
  printf("Fail");
 finalizeTool();
 exit(0);
}
