/*
 * C Program to Calculate Electricity Bill
 */
 
#include <stdio.h>
 
// 1 to 50 units  - 30Rs/unit
// 50 to 100 units - 35Rs/unit
// 100 to 150 units - 40Rs/unit
// 150 units and above - 50Rs/unit
 
int electricity_bill(int units)
{
    if (units <= 50)
    {
        return units * 30;
    }
    else if (units <= 100)
    {
        return (50 * 30) + (units - 50) * 35;
    }
    else if (units <= 150)
    {
        return (50 * 30) + (50 * 35) + (units - 100) * 40;
    }
    else
    {
        return (50 * 30) + (50 * 35) + (50 * 40) + (units - 150) * 50;
    }
}
int main()
{
    int units;
    printf("Enter the units: ");    
    scanf("%d", &units);
    printf("The electricity bill is: %d\n", electricity_bill(units));
    return 0;
}