// x^3+Ax^2+Bx+C=0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

int factors[100000];
int numfactors = 1;
int roots[3];
int rootcount[3];
int numroots;

bool check(int x,int a,int b,int c){
    int a1,b1,c1;
    a1= a*2;
    b1=b;
    c1=0;
    int s = 3*x*x+a1*x+b1;
    if (s==0){
        return 1;
    } else return 0;
}

void addRoot(long long int a, long long int b, long long int c) {
    int num = llabs(c);

    for (int x = -1 * num; x < num; x++) {
        if (x*x*x + a*x*x + b*x + c == 0) {
            roots[numroots] = x;

            if (check(x,a,b,c)==1) {
        rootcount[numroots] = 2;
            } else {
        rootcount[numroots] = 1;
            }

            numroots++;
        }
    }  
}

void printSol(){
    int count = 0;
    for (int i = 0; i < numroots; i++){
            count += rootcount[i];
            printf("%d %d\n", roots[i], rootcount[i]);
    }

    if (count < 1)
        printf("NO SOLUTION\n");
}

int main() {
    long long int a, b, c; // Coefficients of the cubic polynomial
    scanf(" %lld %lld %lld", &a, &b, &c);
    addRoot(a, b, c);
    printSol();

    return 0;
}
