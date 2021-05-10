#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
double myRandom(int *IX);

void main() {
  printf("start");
  FILE *outputfile;
  int IX = 60001;
  int REPETITION;
  double r,r1,r2;
  printf("Input number of repetition\n");
  scanf("%d", &REPETITION);

  outputfile = fopen("output.txt", "w");
  if (outputfile == NULL) {
      printf("cannot open\n");
      exit(1);
  }
  unsigned int count;
  double sum, sum_r_2, ave, var;
  
  for (count = 0; count <= REPETITION; count = count + 1) {
    r = myRandom(&IX);
    fprintf(outputfile, "%30lf\n", r);
  }
  fclose(outputfile);
  printf("end");
}

double myRandom(int *IX) {
  int M = INT_MAX;
  int K = 30517578125; // 5^15
  double rand; // random number
  *IX = ((*IX)*K)&M;
  rand = (double)*IX/M;
  return rand;
}