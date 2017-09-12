/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/09/2017
	Logic -	Modular Exponentiation
	Category - Easy
	Platform - SPOJ
*/	  

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define sz(a) (a).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define p 10000007

ll modularExp(ll x, ll y)
{
	ll res = 1;
	x = x % p;

	while(y>0)
	{
		if(y & 1)
			res = (res*x)%p;
		y = y >> 1;
		x = (x * x)%p;
	}
	return res%p;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	while(1)
	{
		ll n,k;
		cin>>n>>k;

		if(n==0 && k==0)
			break;

		ll a = (2*modularExp(n-1,k) + modularExp(n,k))%p;
		ll b = (2*modularExp(n-1,n-1) + modularExp(n,n))%p;
		a = (a + b)%p;
		cout<<a<<endl;

	}
}