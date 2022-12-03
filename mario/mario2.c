#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Enter the hight of the mario block: ");
    int i, j;
    

    for(i = 0; i <= x; i++){
        for(j = 1; j <= i; j ++){
            printf("#");
        }
        
        printf("\n");
    }
}