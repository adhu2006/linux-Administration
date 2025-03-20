#include <stdio.h>
#include <stdlib.h>
int Add_num(int nParams, char * argv[]);
int main(int argc, char *argv[])
{
printf("Calculate the sum of numbers entered by the user!!!\n");
if(argc < 2)
{
printf("Error: Insufficient parameters!!!\n");
printf("Give at least one or more valid integer numbers as parameters.\n");
return -1;
}
int nParams = argc -1;
int sum = 0;
for(int i = 0; i < argc; i++)
{
printf(" argv[%d] = %s\n", i, argv[i]);
}
sum = Add_num(nParams, argv);
printf("The sum of numbers given is: %d\n", sum);
return 0;
}
int Add_num (int nParams, char * argv[])
{
char *pParam;
int sum = 0;
int num;
pParam = argv[1];
for(int i = 1; i <= nParams; i++ ){
pParam = argv[i]; // Copy the pointer to the first parameter passed
num = atoi(pParam);
sum += num;
printf("pParam = %s, sum = %d\n", pParam, sum);
return sum
}
}
