#include<iostream>
#include<vector>
using namespace std;
//The main idea is to pick primes in ascending order and give nth prime along with the numbers it divides the number n
//This leads to minimal sum since we are count as efficiently as possible
int main()
{long long n,count=2,fact=0;vector<long long> a;
cin>>n;a.resize(n);
for(long long j=2;j<=n;j++)
{if(j%2!=0 && j%3!=0)//Optimisation
 {a[fact]=j;fact++;}}
if(n==2)count=1;//check if n=2 otherwise count is atleast 2 since n>=3
while(a[0]!=0 && a.size()!=0)//repeat until all elements get eliminated
{fact=a[0];
for(long long i=0;a[i]!=0;i++)
{
if(a[i]%fact==0)
{a.erase(a.begin()+i); //suppose we assign the nth prime n+1 and remove all the numbers it divides,then the smallest number left will
                       //be a prime since no smaller prime divided it
i--;
}
}
count++;
}
fact=(count)*(count+1)/2;//1+2+3...n=n(n+1)/2
cout<<fact;
return 0;
}