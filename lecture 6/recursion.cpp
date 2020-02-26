#include <iostream>
#include <vector>

using namespace std;

int factorial (int n) {
    if (n==0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int fibonacci (int n) {
    if (n==0 || n==1) {
        return n;
    }
    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
/*
void revArr (int a[], int i, int j) {
    if (i < j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;

        revArr(A,i+1,j-1);
    }
    return; //this is called tail recursion.. it doesn't do anything but is necessary for recursion. 
}
*/
int main() {
    int n;
    cout << "Find the factorial of n: ";
    cin>>n;
    cout<< "Factorial of "<<n<<" is: \t"<< factorial(n) << endl;

    cout << "Find the fibonacci sequence of n: ";
    cin>>n;
    cout<< "Fibonacci of "<<n<<" is: \t"<< fibonacci(n) << endl;
    return 0;
}
