#include <gsl/gsl_rng.h>
#include <stdio.h>
#include <assert.h>
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
int main(){
 int i;
 
 const int NUM_ITERS=10;
 
 assert(initTool()==0);
 
 for(i=0;i<NUM_ITERS;i++)
  printf("Random Number = %f\n",getRDM());
 
 finalizeTool();
 
 return 0;

}
