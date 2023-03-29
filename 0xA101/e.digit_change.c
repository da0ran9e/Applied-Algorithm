/*
 * C program that takes input as 2323 and gives output as 2332. 
 * ie.the new number should be greater than the previous number
 * but should have the same digits
 */
#include <stdio.h>
#include <math.h>
 
int evaluate(int [], int);
int find(int);
 
int main()
{
    int num, result;
 
    printf("Enter a number: ");
    scanf("%d", &num);
    result = find(num);
    if (result)
    {
        printf("The number greater than %d and made of same digits is %d.\n", num, result);
    }
    else
    {
        printf("No higher value possible. Either all numbers are same or the digits of the numbers entered are in decreasing order.\n");
    }
 
    return 0;
}
 
int find(int num)
{
    int digit[20];
    int i = 0, len = 0, n, temp;
 
    n = num;
    while (n != 0)
    {
        digit[i] = n % 10;
        n = n / 10;
        i++;
    }
    len = i;
    for (i = 0; i < len - 1; i++)
    {
        if (digit[i] > digit[i + 1])
        {
            temp = digit[i];
            digit[i] = digit[i + 1];
            digit[i + 1] = temp;
 
            return (evaluate(digit, len));
        }
    }
 
    return 0;
}
 
int evaluate(int digit[], int len)
{
    int i, num = 0;
 
    for (i = 0; i < len; i++)
    {
        num += digit[i] * pow(10, i);
    }
 
    return num;
}