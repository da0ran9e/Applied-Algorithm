#include <stdio.h>
#include <math.h>

int main() {
   float num, intpart, decpart;

   scanf("%f", &num);

   intpart = floor(num);
   decpart = num - intpart;

   printf("%.0f %.2f\n", intpart, decpart);
   
   return 0;
}
