#include <gsl/rng.h>
#include <stdio.h>
int initTool();
void finalizeTool();
double getRDM();

gsl_rng_type *_gsl_rng_type;
gsl_rng *gsl_rng;

int initTool(){
	_gsl_rng = gsl_rng_alloc(gsl_rng__mt19937);

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
