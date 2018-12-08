#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char **argv ){
 int i;
 int trials = 0;
 int option = 0;
 int verbose =0;
 int successes = 0;
 int pype[2];
 char *percent;
 while((option=getopt(argc,argv,"v::p:"))!=-1){
  switch(option){
   case 'v':
    verbose =1;
    break;
   case 'p':
    percent = optarg;
    break;
   default:
     printf("Invalid Syntax%d:\n",atoi(optarg));
     return 1;
    }
  }
  if(optind<argc){
     trials = atoi(argv[optind]);
   }else{
    return 1;
   }
 //printf("Percent:%s\%\t,Trials:%d\t,isVerbose:%d\n",percent,trials,verbose);
 printf("\n");
 for(i=0;i<trials;i++){
 if(pipe(pype)==-1){
   printf("Bad Pipe\n");
   return 1;
 }
  int peyed = fork();
  if(peyed==0){
   close(pype[0]);
   dup2(pype[1],1);
   execlp("./Hand","Hand","-p",percent,NULL);
  }else{
   close(pype[1]);
   char reading_buf[20];
   while(read(pype[0],reading_buf,20)>0)
   {
   	if(strcmp(reading_buf,"Success")==0)
		successes++;
   	if(verbose==1)
		printf("PID %d returned %s.\n",peyed,reading_buf);
   }
   close(pype[0]);
   wait();
  }
} 
  float rate = (float)successes/trials*100;
  printf("\nCreated %d processes.\nSuccess - %.2f\%\nFailure - %.2f\%\n",trials,rate,100-rate);
 return 0;

}
