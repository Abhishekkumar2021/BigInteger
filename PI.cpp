#include<bits/stdc++.h>
using namespace std;
void printUptoNdigits(int a, int b, int n){
    cout << a/b<<".";
    int upper = a%b;
    int lower = b;
    for (int i = 0; i < n; i++)
    {
        int remainder = upper % lower;
        upper = remainder * 10;
        int quotient = upper / lower;
        cout << quotient;
    }
}
int main(){
    printUptoNdigits(355,113,100);
}