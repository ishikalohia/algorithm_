#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define mod 1000000007
vector<int> * sieve()
{
    bool isprime[MAX];
    for(int i=0;i<=MAX;i++)
    isprime[i]=true;
    vector<int> * primes = new vector<int>();
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=MAX;i++)
    {
        if(isprime[i]==true)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    primes->push_back(2);
    for(int i=3;i<=MAX;i=i+2)
    {
        if(isprime[i]==true)
        {
            primes->push_back(i);
        }
    }
    return primes;
}
long long divisors(int a,int b,int n,vector<int> * &primes)
{
    long long result = 0;
    for(int i=a;i<=b;i++)
    {
        long long count = 0;
        long long j = 0;
        long long p = primes->at(j);
        long long k = i;
        while(k/p!=0)
		{
            if(k%p==0)
                count++;
         	j++;
        	p = primes->at(j);
        }
        if(count==n)
            result++;
    }
    return result;
}
int main(){
    vector<int> * primes = sieve();
    int t;
    cin>>t;
    while(t>0)
    {
        t--;
        int a,b,n;
        cin>>a>>b>>n;
        if(n==0 && a==1)
        {
            cout<<1<<endl;
            continue;
        }
        cout<<divisors(a,b,n,primes)<<endl;
    }
}
