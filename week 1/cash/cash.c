#include <cs50.h>
#include <stdio.h>

int coinCounter(int cents);

int main(void)
{
    int cents, i, j, numberOfChange;
    //  do while loop to get total cents by user input bigger than 0
    do
    {
        cents = get_int("total change owed: ");
    }
    while (cents < 1);

    numberOfChange = coinCounter(cents);

    printf("%d", numberOfChange);
}

int coinCounter(int cents)
{
    int numberOfChange = 0;

    if (cents >= 25)
    {
        numberOfChange += cents / 25;
        cents = cents % 25;
    }
    if (cents >= 10)
    {
        numberOfChange += cents / 10;
        cents = cents % 10;
    }
    if (cents >= 5)
    {
        numberOfChange += cents / 5;
        cents = cents % 5;
    }
    if (cents >= 1)
    {
        numberOfChange += cents / 1;
        cents = cents % 1;
    }

    return numberOfChange;
}
 