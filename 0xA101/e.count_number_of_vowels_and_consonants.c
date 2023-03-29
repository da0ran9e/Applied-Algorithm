/*
 * C program to read a sentence and count the total number of vowels
 * and consonants in the sentence.
 */
#include <stdio.h>
 
void main()
{
    char sentence[80];
    int i, vowels = 0, consonants = 0, special = 0;
 
    printf("Enter a sentence \n");
    gets(sentence);
    for (i = 0; sentence[i] != '\0'; i++)
    {
        if ((sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] ==
        'i' || sentence[i] == 'o' || sentence[i] == 'u') ||
        (sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] ==
        'I' || sentence[i] == 'O' || sentence[i] == 'U'))
        {
            vowels = vowels + 1;
        }
        else
        {
            consonants = consonants + 1;
        }
        if (sentence[i] =='\t' ||sentence[i] =='\0' || sentence[i] ==' ')
        {
            special = special + 1;
        }
    }
    consonants = consonants - special;
    printf("No. of vowels in %s = %d\n", sentence, vowels);
    printf("No. of consonants in %s = %d\n", sentence, consonants);
} 