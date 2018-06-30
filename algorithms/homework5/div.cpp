#include <iostream>
using namespace std;

int maxUsingDivConq(int a[], int left, int right){
   if (right - left==1)
   {
       return a[left];
   }
   int mid = (left + right)/2;
   int u = maxUsingDivConq(a, left, mid);
   int v = maxUsingDivConq(a, mid, right);
   return u>v?u:v;  
   if (u > v)
   {
       return u;
   }
   else
   {
       return v;
   }
}

int main() {
    int a[] = {1, 3, 11, 7, 5, 6, 4, 9};
    int n = sizeof(a)/sizeof(int);
    cout << maxUsingDivConq(a,0,n) << endl;         
    return 0;
}