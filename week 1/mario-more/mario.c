#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height , i, j;

     //  do while loop to get height by user input between 1 to 8
    do
    {
        height = get_int("Height: ");
    }while((height<1) || (height>8));

     // double for loop to make the double pyramid for mario
    for(i = 1;i<=height;i++)
    {
        for(j = 1; j <= ((height*2) + 2) ;j++)
        {
            if((j == height+1) || (j == height+2))            {
                printf(" ");
            }
            else if(j <= height)
            {
                 if((j<=height) && (j>=height+1-i))
                    {
                    printf("#");
                    }
                 else{
                        printf(" ");
                    }

            }
            else if(j>height+2)
            {
                if(j<=(i+height+2))
                {
                    printf("#");
                }
            }

        }
        printf("\n");
    }
}
