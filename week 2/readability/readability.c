#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calcLetters(string userinput);
int calcSentences(string userinput);
int calcWords(string userinput);

int main(void)
{
    string userinput = get_string("enter your paragraph: ");

    int Letter = calcLetters(userinput);
    int Sentence = calcSentences(userinput);
    int Word = calcWords(userinput);

    // printf("no. of letters: %d \n",Letter);
    // printf("no. of words: %d",Word);
    // printf("no. of Sentence: %d \n",Sentence);

    float l = ((float)Letter/(float)Word)*100;
    int s = ((float)Sentence/(float)Word)*100;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    index = round(index);
    // printf("%d",(int)index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int)index);
    }


}

int calcLetters(string userinput)
{
    int lenght = strlen(userinput);
    int letters = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(userinput[i]))
        {
            letters++;
        }
        else
        {
            continue;
        }

    }

    return letters;
}

int calcSentences(string userinput)
{
    int lenght = strlen(userinput);
    int sentences = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (userinput[i] == '.' || userinput[i] == '!' || userinput[i] == '?')
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }

    return sentences;
}

int calcWords(string userinput)
{
    int lenght = strlen(userinput);
    int words = 0;
    for (int i = 0; i <= lenght; i++)
    {
        if (userinput[i] == ' ' || userinput[i] == '\n' || userinput[i] == 0)
        {
            words++;
        }
        else
        {
            continue;
        }
    }
    return words;
}
