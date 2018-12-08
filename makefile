makeDealer: dealer.c
	gcc $^ -o dealer -lgsl -L$$HOME/local/gsl-2.5/lib -lgslcblas -I$$HOME/local/gsl-2.5/include
makeHand: hand.c
	gcc $^ -o hand -lgsl -L$$HOME/local/gsl-2.5/lib -lgslcblas -I$$HOME/local/gsl-2.5/include
