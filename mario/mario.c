#include <stdio.h>
#include <cs50.h>

int main()
{
    int n, i, j;
   do
   {
       n = get_int("\nHight:");

   }
   while(n > 8 || n< 1);
   

   for (i=1; i<=n; i++)
   {
       for (j = 1; j <= n * 3 + 1; j++)
       {
       if (j == n + 1 || j == n + 2)
       {
           printf(" ");
       }
       else if(j >= n + 1 - i && j <= n + i + 2)
       {
           printf("#");
       }
       else if(j < n + 1 - i)
       {
           printf(" ");
       }

       }
       printf("\n");
       
   }
   return n;
}