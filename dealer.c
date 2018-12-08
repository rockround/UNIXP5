#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char **argv ){
 int i;
 int percent = 0;
 int trials = 0;
 int option = 0;
 int verbose =0;
 int pype[2];
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
     trials = atoi(argv[optind]);
   }else{
    return 1;
   }
 printf("Percent:%d\t,Trials:%d\t,isVerbose:%d\n",percent,trials,verbose);
 if(pipe(pype)==-1){
   printf("Bad Pipe\n");
   return 1;
 }
 for(i=0;i<trials;i++){
  int peyed = fork();
  if(peyed==0){
   close(pype[0]);
   dup2(pype[1],1);
   execlp("Hand","Hand","-p","100");
   //system("./Hand -p 100");
  }else{
   close(pype[1]);
   char reading_buf[1];
   while(read(pype[0],reading_buf,1)>0)
   {
   	write(1,reading_buf,1);
   }
   close(pype[0]);
   wait();
  }
}
 
 return 0;

}
