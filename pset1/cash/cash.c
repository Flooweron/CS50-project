#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    float change;
    int counter = 0;
    int division;
    int mod;
    float quarter = 25, dime = 10, nickel = 5, penny = 1;

    do
    {
        change = get_float("Change owed: \n");
    }
    while (change <= 0);
    change = change * 100;

    while (change >= quarter)
        
    {  
        change = nearbyintf(change - quarter);
        counter += 1;
    }
    while (change >= dime)
    {
        change = nearbyintf(change - dime);
        counter += 1;
    }
    while (change >= nickel)
    {
        change = nearbyintf(change - nickel);
        counter += 1;
    }
    while (change >= penny)
    {
        change = nearbyintf(change - penny);
        counter += 1;
    }
    printf("%d\n", counter);
    return (0);
       
}