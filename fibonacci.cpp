#include <bits/stdc++.h>
using namespace std;

int recFibonacci(int n){
    if(n <= 1)
        return n;
    return recFibonacci(n -1) + recFibonacci(n -2); 
}

void multiplication(int F[2][2], int M[2][2]){ // F = F* M
    int w = F[0][0]*M[0][0] + F[0][1]*M[1][0];  // new F[0][0]
    int x = F[0][0]*M[0][1] + F[0][1]*M[1][1];  // new F[0][1]
    int y = F[1][0]*M[0][0] + F[1][1]*M[1][0];  // new F[1][0]
    int z = F[1][0]*M[0][1] + F[1][1]*M[1][1];  // new F[1][1]

    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}

void power(int F[2][2],int n){
    if(n<=1)
        return;
    int M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiplication(F, F);
    if(n%2 !=0)
        multiplication(F,M);
}
// Divide & Conquer (Matrix Multiplication)
int fibonacciMatrix(int n){
    if (n == 0)
        return 0;
    int F[2][2] ={{1,1},{1,0}};
    power(F, n-1);
    return F[0][0];
}

int DpFibonacci(int n){ //Bottom-up
   if (n <= 1)
        return n;
    //starting from base cases upward
    int a = 0, b = 1, c; //a= F[n-1],b=F[n-2]

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;      
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive Fibonacci for " << n << " = " << recFibonacci(n) << endl;
    cout << "Matrix Fibonacci for " << n << " = " << fibonacciMatrix(n) << endl;
    cout << "Dp Fibonacci for " << n << " = " << DpFibonacci(n) << endl;

    return 0;
}
