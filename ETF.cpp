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
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define MAXN 1000005

vi spf(MAXN);

void sieve()
{
	spf[1] = 1;
	loop(i,2,MAXN)
		spf[i] = i;
	for(ll i=4;i<MAXN;i+=2)
		spf[i] = 2;
	for(ll i=3;i*i<MAXN;i+=2)
	{
		if(spf[i]==i)
		{
			for(ll j=i*i;j<MAXN;j+=i)
			{
				if(spf[j]==j)
					spf[j] = i;
			}
		}
	}
}

ll getFactors(ll n)
{
	ll temp = n;
	while(n!=1)
	{
		temp = (temp/spf[n])*(spf[n]-1);
		ll x = spf[n];
		while(n%x==0)
			n = n/x;
	}
	return temp;
}

int main()
{
	std::ios::sync_with_stdio(false);
	sieve();
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;

		cout<<getFactors(n)<<endl;
	}
	return 0;
}