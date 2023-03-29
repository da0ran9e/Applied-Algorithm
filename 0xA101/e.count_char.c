#include <stdio.h>
#include <string.h>
 
// A structure to store characters and its 
// frequency in input string
struct CharCount
{
    char c;
    int count;
};
 
// A utility function to check if given character
// is present in CharCount array or not
int findInArray(struct CharCount *a, char x, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i].c == x)
            return i;
    }
    return -1;
}
 
// This function returns the characters with
// their frequency in an alphabetically 
// sorted order
void printCharWithFreq(char *str)
{
    int n = strlen(str);
    struct CharCount a[n];
    int i, j = 0;
     
    // First store all characters with their
    // frequencies in a temporary array
    for (i = 0; i < n; i++)
    {
        int found = findInArray(a, str[i], j);
        if (found == -1)
        {
            a[j].c = str[i];
            a[j].count = 1;
            j++;
        }
        else
            a[found].count += 1;
    }
 
    // Sort the temp array using Bubble Sort
    for (i = 0; i < j; i++)
    {
        for (int k = 0; k <j-1; k++)
        {
            if (a[k].c > a[k+1].c)
            { 
                char temp = a[k].c; 
                a[k].c = a[k+1].c; 
                a[k+1].c = temp; 
                     
                // Swap associated counts 
                int tempi = a[k].count; 
                a[k].count = a[k+1].count; 
                a[k+1].count = tempi; 
            } 
        } 
    }
 
    // Print the result
    for (i = 0; i < j; i++)
        printf("%c %d\n", a[i].c, a[i].count);
}
#include <stdio.h>
#include <string.h>

// structure definition 
struct Student { 
   char name[50]; 
   int roll; 
   int marks; 
}; 

int main() 
{ 
    struct Student s;

    // Input a string and store it using strcpy() 
    printf("Enter Name:");
    scanf("%s", s.name); 
  
    // input roll number and marks 
    printf("Enter Roll Number:");
    scanf("%d", &s.roll); 
  
    printf("Enter Marks: ");
    scanf("%d", &s.marks); 
  
    // print the values 
    printf("Name: %s\n", s.name); 
    printf("Roll No.: %d\n", s.roll); 
    printf("Marks: %d\n", s.marks); 
  
    return 0; 
} 
int main(void) {
    struct Data data;
 
    printf("Enter a string and two integers: ");
    scanf("%99s%d%d", data.str, &data.x, &data.y);
 
    printf("You entered %s, %d, %d\n", 
          data.str, data.x, data.y);
    return 0;
}
void sort(int n, int* ptr)
{
int i, j, t;
// Sort the numbers using pointers
for (i = 0; i < n; i++) {
for (j = i + 1; j < n; j++) {
if (*(ptr + j) < *(ptr + i)) {
t = *(ptr + i);
*(ptr + i) = *(ptr + j);
*(ptr + j) = t;
}
}
} /
/ print the numbers
for (i = 0; i < n; i++)
printf("%d ", *(ptr + i));
}