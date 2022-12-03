#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long count, a, x, z;
    double s = 0.01;
    int b = 10;
    int  yy, sum = 0, digit=0;
    do
    {
        printf("Enter: ");
        scanf("%lld", &a);
        x = a;
        z = x;
        digit = 0;
        do
        {
        x /= 10;
        digit++;
        s *= 10;
        }
        while(x != 0);
        
    }
    while(digit <=12 || digit >= 17);
    
int dev = a / (long long)s;

    do
    {
        count = a / b;
        
        int y = count % 10;
        
        yy = y * 2;
        
        if(yy >= 10)
        {
          sum += 1 + (yy % 10);
        }
        else
        {
            sum += yy;
        }
        
        a = count;
        b = 100;
    }
    while(count != 0);
   

long long co;
int rem, add=0;

    do
    {
        b = 100;
        rem = z % b;
        if(rem >= 10)
        {
            rem %= 10;
        }
        co = z / b;
        add += rem;
        z = co;
    }
    while(co != 0);

int total = sum + add;
 

    if(total % 10 == 0)
    {
        if(dev >= 40 && dev <50)
        {
            printf("Visa card!\n");
        }
        else if(dev == 34 || dev == 37)
        {
            printf("AMerican Express.\n");
        }
        else if(dev > 50 && dev <= 55)
        {
            printf("Mastercard.\n");
        }
        else
        {
            printf("sorry! invalid");
        }

    }
    else
    {
        printf("sorry! invalid\n");
    }
}
