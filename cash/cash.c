#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cash;
    int x, a = 1, b = 5, c = 10, d = 25, coin = 0;
    
    do
    {
        printf("Cash: ");
        scanf("%f", &cash);
        if( typeof(cash) != float)
        {
            cash = -1;
        }
    }
    while(cash < 0);

    x = round(cash * 100);
    
   
    do 
    {
       if(x / d != 0)
       {
        x -= d;
        coin++;
       }
    else if(x / c != 0 && x < d) 
       {
           x -= c;
           coin++;
       }
    else if(x / b != 0 && x < c)
       {
           x -= b;
           coin++;
       }
    else if(x / a != 0 && x < b)
       {
           x -= a;
           coin++;
       }
    }while(x > 0);
    printf("coin: %d\n", coin);
   
}