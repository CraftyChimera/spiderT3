#include<iostream>
#include<vector>
using namespace std;
//This is a dynamic programming approach
long long maxstr(vector<long long> a,long long n,long long sum)
{long long w;
w=sum/2;//This function is computing the max possible sum of the subset with lower sum.Hence <=sum/2 constraint holds
long long dp[n+1][w+1];//dp[x][y] is the maximum strength of brick taking a subset {a_1,a_2...a_x} from {a_1,a_2...a_x} and assuming max sum to be less than x.
for(long long x=0;x<=w;x++)
dp[0][x]=0;//if no elements of the set are picked,then max strength is clearly 0
for(long long i=1;i<=n;i++)
{dp[i][0]=0;
for(long long x=0;x<=w;x++)
{if(a[i-1]<=x)//suppose you have an optimal solution with subset {a_1,a_2...a_{i-1}},your optimal solution with including
 //a_{i} would either be not considering it(as it might mess up the arrangement) or to consider it and maximise the remaining stuff
 //we take max of both cases and store it as optimal solution
 dp[i][x]=max(dp[i-1][x],a[i-1]+dp[i-1][x-a[i-1]]);
 else
 dp[i][x]=dp[i-1][x];
}
}
return dp[n][w];//optimal solution with the total set and w=sum/2
}

int main()
{vector<long long>a;long long n=0,t=0,sum=0;
cin>>t;
cin>>n;
a.resize(n);
for(long i=0;i<n;i++)
{cin>>a[i];sum+=a[i];}
if(t==2) //if t==2 we divide the set into 2 subsets and apply the logic above
{if(n>1)cout<<maxstr(a,n,sum);
else cout<<0;
}
else
cout<<sum;
return 0;}

