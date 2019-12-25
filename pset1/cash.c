#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change = get_float("Change Owed:\n");
    while (change < 0)
    {
        change = get_float("Change Owed:\n");
    }

    int cents = round(change * 100);
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int nc = 0;
    int x;

    while (cents >= quarter)
    {
        x = (cents/quarter);
        nc = nc + x;
        cents = cents - (quarter * x);
        break;
    }

    while (cents >= dime)
    {
        x = (cents/dime);
        nc = nc + x;
        cents = cents - (dime * x);
        break;
    }

    while (cents >= nickel)
    {
        x = (cents/nickel);
        nc = nc + x;
        cents = cents - (nickel * x);
        break;
    }

    while (cents >= penny)
    {
        x = (cents/penny);
        nc = nc + x;
        cents = cents - (penny * x);
        break;
    }

    printf("Coins Owed: %i\n", nc);
}


