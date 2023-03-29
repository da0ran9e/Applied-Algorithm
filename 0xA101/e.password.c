/*
 * C program is to illustrate how user authentication is done.
 * Program asks for the user name and password and displays
 * the password as '*' character
 */
#include <stdio.h>
 
void main()
{
	char password[10], username[10], ch;
	int i;
 
	printf("Enter User name: ");
	gets(username);
	printf("Enter the password < any 8 characters>: ");
	for (i = 0; i < 8; i++)
	{
            ch = getchar();
            password[i] = ch;
            ch = '*' ;
            printf("%c", ch);
	}
        password[i] = '\0';
	/*  Original password can be printed, if needed */
	printf("\n Your password is :");
	for (i = 0; i < 8; i++)
	{
            printf("%c", password[i]);
	}
}