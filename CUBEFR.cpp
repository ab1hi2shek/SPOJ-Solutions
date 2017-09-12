/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/09/2017
	Logic -	Number theory
	Category - Easy
	Platform - SPOJ
*/	  

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
#define MAXM 1000005

ll sieve[MAXM];

void init()
{
	memset(sieve, -1, sizeof(sieve));
	for(ll i=2; i*i*i<=MAXM; i++)
	{
		ll temp = i*i*i;
		for(ll j=1;j<=MAXM;j++)
		{
			if(j % temp == 0)
				sieve[j] = 0;
		}
	}

	ll tt = 1;
	for(ll i=1;i<=MAXM; i++)
	{
		if(sieve[i] == -1)
			sieve[i] = tt++;
	}

	// for(ll i=1;i<=25;i++)
	// 	cout<<sieve[i]<<" ";
	// cout<<endl;
}

int main()
{
	std::ios::sync_with_stdio(false);

	init();
	ll t;
	cin>>t;
	ll q = 1;
	while(t--)
	{
		ll n;
		cin>>n;

		if(sieve[n] == 0)
			cout<<"Case "<<q++<<": "<<"Not Cube Free"<<endl;
		else
			cout<<"Case "<<q++<<": "<<sieve[n]<<endl;
	}
}