/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
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

//to find (a*b)%c without overflowing
ll mulmod(ll a, ll b, ll mod)
{
	ll res = 0, temp = a % mod;
	while( b != 0 )
	{
		if(b%2==1)
			res = (res + temp) % mod;
		temp = (2*temp) % mod;
		b /= 2;
	}
	return res % mod;
}

//to find (a^b)%c in )(log n)
ll modular(ll a, ll b, ll mod)
{
	ll res = 1;
	ll temp = a % mod;

	while(b != 0)
	{
		if(b%2==1)
			res = mulmod(res,temp,mod);
		temp = mulmod(temp,temp,mod);

		b /= 2;
	}
	return res % mod;
}

bool millerRabin(ll n)
{
	if(n==2)
		return true;
	if(n<2 || n%2==0)
		return false;

	ll s = n-1;
	while(s%2==0)
		s /=2;

	for(ll i=0;i<50;i++)
	{
		ll a = rand() % (n-1) + 1;
		ll temp = s;
		ll mod = modular(a,temp,n);
		while(temp!=n-1 && mod!=1 && mod!=n-1)
		{
			mod = mulmod(mod,mod,n);
			temp *= 2;
		}
		if(mod!=n-1 && temp%2==0)
			return false;
	}
	return true;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;

		if(millerRabin(n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}