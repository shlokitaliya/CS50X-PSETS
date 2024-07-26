#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //  variable declaration
    int height, i , j;
    //  do while loop to get height by user input between 1 to 8
    do{
        height = get_int("Height: ");
    }while((height<1) || (height>8));

    // double for loop to make the pyramid for mario
    for(i = 1;i<=height;i++)
    {
        for(j = 1; j<=height ;j++)
        {
            if((j<=height) && (j>=height+1-i))
            {
            printf("#");
            }
            else{
                printf(" ");
            }

        }
        printf("\n");
    }
}
