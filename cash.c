#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coin = 0;

    // Get user input
    do
    {
       change = get_float("Change owed: ");
    }
    while (change < 0);

    // Convert to integer
    int changeCents = round(change * 100);

    while ((changeCents - 25) >= 0)
    {
        changeCents = changeCents - 25;
        coin++;
    }

    while ((changeCents - 10) >= 0)
    {
        changeCents = changeCents - 10;
        coin++;
    }

    while ((changeCents - 5) >= 0)
    {
        changeCents = changeCents - 5;
        coin++;
    }

    while ((changeCents - 1) >= 0)
    {
        changeCents = changeCents - 1;
        coin++;
    }

    printf("%i\n", coin);

}
