
#define MAX 100000
#define MIN 0

#include <stdio.h>
#include <cs50.h>



int main()
{
 int k = get_int("Введите число!\n");
 int facK = 1;
 
 
 if ((k < MIN) || (k > MAX))
  {
    printf("FALLS\n");
    return 1;
  }
  
 for (int i = 1; i <= k; i++) {
   if(i%10==0) continue;
   else facK*=i;
   if(facK%10==0) facK/=10;
 }
      
      facK%=10;
      printf("%i\n", facK);
}


