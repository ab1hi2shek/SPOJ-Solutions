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
// #define isPowerOfTwo(S) !(S & (S - 1))
// #define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
// #define nline cout<<endl
// #define MAX 1000005
//int prime[MAX];

// void sieve()
// {
// 	for(ll i=0;i<MAX;i++)
// 		prime[i] = 0;
// 	ll p = n;

// 	for(ll i=2; i<=sqrt(p); i++)
// 	{
// 		if(p%i==0)
// 		{
// 			prime[i] = 0;
// 			prime[p/i] = 0;
// 		}
// 	}
	
// }
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

//	sieve();

	while(t--)
	{
		ll n;
		cin>>n;

		cout<<(n+1)/2<<endl;
	}
}